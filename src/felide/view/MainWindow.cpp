
#include "MainWindow.hpp"

#include <sstream>
#include <iostream>
#include <boost/functional/hash.hpp>
#include <boost/filesystem.hpp>

#include <QFileDialog>
#include <QCloseEvent>
#include <QMessageBox>

#include <felide/view/SourceEditorGeneric.hpp>

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
        this->onNewFile();
    }
    
    void MainWindow::initializeUserInterface()
    {
        this->initializeMenuBar();
        this->initializeEditor();
        this->connectSignals();
    }
    
    void MainWindow::initializeEditor()
    {
        this->sourceEditor = new SourceEditorGeneric(this);
        
        QObject::connect(this->sourceEditor, &SourceEditor::editorChanged, this, &MainWindow::onEditorChanged);
        
        this->setCentralWidget(this->sourceEditor);
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
    }
    
    void MainWindow::updateEditorMargin() 
    {
        /*
        QFontMetrics fontmetrics = this->editorWidget->fontMetrics();
        this->editorWidget->setMarginWidth(0, fontmetrics.width(QString::number(this->editorWidget->lines())) + 6);
        */
    }
    
    void MainWindow::onEditorChanged(const QString &title) 
    {
        std::cout << "editorChanged" << std::endl;
        
        std::stringstream ss;
        
        ss << "felide - " << title.toStdString();
        
        this->setWindowTitle(QString(ss.str().c_str()));
        this->sourceEditor->getProjectItem()->setDirtyFlag(true);
        this->updateEditorMargin();
    }
    
    void MainWindow::onNewFile() 
    {
        if (this->sourceEditor->getProjectItem()->getDirtyFlag()) {
            switch (this->askSaveChanges()) {
                case QMessageBox::Save:
                    if (!this->onSaveFile()) {
                        return;
                    }
                
                case QMessageBox::Cancel:
                    return;
            }
        }
        
        this->sourceEditor->new_();
    }
    
    bool MainWindow::onOpenFile() 
    {   
        // Check for previous file
        if (this->sourceEditor->getProjectItem()->getDirtyFlag()) {
            switch (this->askSaveChanges()) {
                case QMessageBox::Save:
                
                    if (!this->onSaveFile()) {
                        return false;
                    }
                
                case QMessageBox::Cancel:
                    return false;
            }
        }
        
        // Open the file
        QString path = QFileDialog::getOpenFileName(this, "Open", QString(), tr(fileFilter));
        
        if (path.isEmpty()) {
            return false;
        }
        
        this->sourceEditor->load(path);
        
        return true;
    }
    
    bool MainWindow::onSaveFile() 
    {
        if (this->sourceEditor->getProjectItem()->hasPath()) {
            this->sourceEditor->save();
            
            return true;
        } else {
            return this->onSaveFileAs();
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
    
    bool MainWindow::onSaveFileAs() 
    {
        QString path = QFileDialog::getSaveFileName(this, "Save", QString(), tr(fileFilter));
        
        if (path.isEmpty()) {
            return false;
        }
        
        this->sourceEditor->save(path);
        
        return true;
    }
    
    void MainWindow::closeEvent(QCloseEvent *event) 
    {
        if (!this->sourceEditor->getProjectItem()->getDirtyFlag()) {
            event->accept();
            return;
        }
        
        switch (this->askSaveChanges()) {
            case QMessageBox::Save:
                if (this->onSaveFile()) {
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
        this->sourceEditor->undo();
    }
    
    void MainWindow::onRedo()
    {
        this->sourceEditor->redo();
    }
    
    void MainWindow::onCut()
    {
        this->sourceEditor->cut();
    }
    
    void MainWindow::onCopy()
    {
        this->sourceEditor->copy();
    }
    
    void MainWindow::onPaste()
    {
        this->sourceEditor->paste();
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
