
#include "MainWindow.hpp"

#include <sstream>
#include <boost/functional/hash.hpp>
#include <boost/filesystem.hpp>

#include <QFileDialog>
#include <QCloseEvent>
#include <QMessageBox>
#include <Qsci/qscilexercpp.h>
#include <Qsci/qscilexercmake.h>

namespace felide { namespace view {
    
    namespace fs = boost::filesystem;
    
    const char fileFilter[] = "C/C++ Source Files (*.cpp *.hpp *.c *.h);;All Files (*.*)";
    
    std::string getTempPath() 
    {
        return "/var/tmp/felide/";
    }
    
    MainWindow::MainWindow() 
    {
        this->initializeUserInterface();
    }
    
    void MainWindow::initializeUserInterface()
    {
        this->initializeMenuBar();        
        this->updateTitle();
    }
    
    void MainWindow::addSourceEditor() 
    {
        this->initializeWindow();
        this->initializeEditor();
        this->connectSignals();
    }
    
    MainWindow::~MainWindow() {}
    
    void MainWindow::initializeMenuBar() 
    {
        this->fileMenu = this->menuBar()->addMenu("&File");
        
        this->newFileAction = this->fileMenu->addAction("&New");
        this->newFileAction->setShortcut(QKeySequence::New);
        this->openFileAction = this->fileMenu->addAction("&Open ...");
        this->openFileAction->setShortcut(QKeySequence::Open);
        this->saveFileAction = this->fileMenu->addAction("&Save");
        this->saveFileAction->setShortcut(QKeySequence::Save);
        this->saveAsFileAction = this->fileMenu->addAction("Save &As ...");
        
        this->fileMenu->addSeparator();
        
        this->exitAction = this->fileMenu->addAction("&Exit");
        
        this->editMenu = this->menuBar()->addMenu("&Edit");
        this->undoAction = this->editMenu->addAction("&Undo");
        this->undoAction->setShortcut(QKeySequence::Undo);
        this->redoAction = this->editMenu->addAction("&Redo");
        this->redoAction->setShortcut(QKeySequence::Redo);
        
        this->editMenu->addSeparator();
        
        this->cutAction = this->editMenu->addAction("&Cut");
        this->cutAction->setShortcut(QKeySequence::Cut);
        this->copyAction = this->editMenu->addAction("C&opy");
        this->copyAction->setShortcut(QKeySequence::Copy);
        this->pasteAction = this->editMenu->addAction("&Paste");
        this->pasteAction->setShortcut(QKeySequence::Paste);
        
        this->testMenu = this->menuBar()->addMenu("&Test");
        this->testAction = this->testMenu->addAction("T&est");
        
        this->compileMenu = this->menuBar()->addMenu("&Compile");
        this->buildAction = this->compileMenu->addAction("&Build");
        this->buildAction->setShortcut(tr("Ctrl+Shift+B"));
        this->compileMenu->addSeparator();
        this->executeAction = this->compileMenu->addAction("&Execute");
        this->executeAction->setShortcut(tr("Ctrl+F5"));
    }
    
    void MainWindow::initializeWindow() 
    {

    }
    
    void MainWindow::connectSignals() 
    {
        this->connect(this->newFileAction, SIGNAL(triggered()), this, SLOT(onNewFile()));
        this->connect(this->openFileAction, SIGNAL(triggered()), this, SLOT(onOpenFile()));
        this->connect(this->saveFileAction, SIGNAL(triggered()), this, SLOT(onSaveFile()));
        this->connect(this->saveAsFileAction, SIGNAL(triggered()), this, SLOT(onSaveFileAs()));
        this->connect(this->exitAction, SIGNAL(triggered()), this, SLOT(onExit()));
        
        this->connect(this->undoAction, SIGNAL(triggered()), this, SLOT(onUndo()));
        this->connect(this->redoAction, SIGNAL(triggered()), this, SLOT(onRedo()));
        this->connect(this->cutAction, SIGNAL(triggered()), this, SLOT(onCut()));
        this->connect(this->copyAction, SIGNAL(triggered()), this, SLOT(onCopy()));
        this->connect(this->pasteAction, SIGNAL(triggered()), this, SLOT(onPaste()));
        
        this->connect(this->testAction, SIGNAL(triggered()), this, SLOT(onTest()));
    }
    
    void MainWindow::updateTitle() 
    {
        std::stringstream ss;
        
        ss << "felide - ";
        if (this->source.hasPath()) {
            ss << this->source.getPath() << " ";
        } else {
            ss << "Untitled " << this->documentCount << " ";
        }
        
        ss << (this->source.getDirtyFlag()?"[modified]":"");
        
        this->setWindowTitle(QString(ss.str().c_str()));
    }
    
    void MainWindow::updateEditorMargin() 
    {
        QFontMetrics fontmetrics = this->editorWidget->fontMetrics();
        this->editorWidget->setMarginWidth(0, fontmetrics.width(QString::number(this->editorWidget->lines())) + 6);
    }
    
    void MainWindow::onTextChanged() 
    {
        this->source.setDirtyFlag(true);
        
        this->updateEditorMargin();
        this->updateTitle();
    }
    
    void MainWindow::onNewFile() 
    {
        if (this->sourceEditor->getDirtyFlag()) {
            switch (this->askSaveChanges()) {
                case QMessageBox::Save:
                    if (!this->doSaveFile()) {
                        return;
                    }
                
                case QMessageBox::Cancel:
                    return;
            }
        }
        
        this->documentCount++;
        
        this->source = felide::model::Source();
        this->updateTitle();
    }
    
    void MainWindow::onOpenFile() 
    {    
        if (this->source.getDirtyFlag()) {
            switch (this->askSaveChanges()) {
                case QMessageBox::Save:
                    if (!this->doSaveFile()) {
                        return;
                    }
                
                case QMessageBox::Cancel:
                    return;
            }
        }
        
        this->doOpenFile();
    }
    
    void MainWindow::onSaveFile() 
    {
        if (this->source.hasPath()) {
            this->source.save(this->editorWidget->text().toStdString());
            this->updateTitle();
        } else {
            this->onSaveFileAs();
        }
    }
    
    int MainWindow::askSaveChanges() 
    {
        QMessageBox msgBox;
        msgBox.setText("The document has been modified.");
        msgBox.setInformativeText("Do you want to save your changes?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        
        return msgBox.exec();
    }
    
    void MainWindow::onSaveFileAs() 
    {
        this->doSaveFile();
    }
    
    bool isExtensionCpp(const std::string &ext) 
    {
        return ext==".c" || ext==".h" || ext==".cpp" || ext==".hpp";
    }
    
    static QsciLexer* createLexer(const std::string &filename) 
    {
        QsciLexer *lexer = nullptr;
        
        // Select correct lexer type
        fs::path path = fs::path(filename);
        fs::path name = path.filename();
        
        if (isExtensionCpp(name.extension().string())) {
            QsciLexerCPP *cppLexer = new QsciLexerCPP();
            cppLexer->setFoldComments(true);
            
            lexer = cppLexer;
        }
        
        if (name.string() == "CMakeLists.txt") {
            lexer = new QsciLexerCMake();
        }
        
        return lexer;
    }
    
    void MainWindow::setLexer(QsciLexer *lexer)
    {
        if (lexer) {
            lexer->setDefaultFont(this->editorWidget->font());
        }
        
        this->editorWidget->setLexer(lexer);
    }
    
    bool MainWindow::doOpenFile() 
    {
        QString path = QFileDialog::getOpenFileName(this, "Open", QString(), tr(fileFilter));
        
        if (path.isEmpty()) {
            return false;
        }
        
        this->setLexer(createLexer(path.toStdString()));
        
        std::string content;
        this->source = felide::model::Source(path.toStdString());
        content = this->source.load();
        this->editorWidget->setText(QString(content.c_str()));
        
        this->source.setDirtyFlag(false);
        
        this->updateTitle();
        
        return true;
    }
    
    bool MainWindow::doSaveFile() 
    {
        QString path = QFileDialog::getSaveFileName(this, "Save", QString(), tr(fileFilter));
        
        if (path.isEmpty()) {
            return false;
        }
        
        this->setLexer(createLexer(path.toStdString()));
        
        std::string content = this->editorWidget->text().toStdString();
        
        this->source = felide::model::Source(path.toStdString());
        this->source.save(content);
        
        this->updateTitle();
        
        return true;
    }
    
    void MainWindow::closeEvent(QCloseEvent *event) 
    {
        if (!this->source.getDirtyFlag()) {
            event->accept();
            return;
        }
        
        switch (this->askSaveChanges()) {
            case QMessageBox::Save:
                if (this->doSaveFile()) {
                    event->accept();
                } else {
                    event->ignore();
                }
                break;
            
            case QMessageBox::Discard:
                event->accept();
                break;
                
            case QMessageBox::Cancel:
                event->ignore();
                break;
        }
    }
    
    void MainWindow::onExit() 
    {
        this->close();
    }
    
    void MainWindow::onUndo() 
    {
        this->editorWidget->undo();
    }
    
    void MainWindow::onRedo()
    {
        this->editorWidget->redo();
    }
    
    void MainWindow::onCut()
    {
        this->editorWidget->cut();
    }
    
    void MainWindow::onCopy()
    {
        this->editorWidget->copy();
    }
    
    void MainWindow::onPaste()
    {
        this->editorWidget->paste();
    }
    
    void MainWindow::onTest() 
    {
        
    }
    
    void MainWindow::onBuild() 
    {
        
    }
    
    void MainWindow::onExecute()
    {
        
    }
}}
