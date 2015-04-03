
#include "MainWindow.hpp"

#include <sstream>
#include <iostream>

#include <QFileDialog>
#include <QCloseEvent>
#include <QMessageBox>

#include <felide/view/SourceEditorGeneric.hpp>

namespace felide { namespace view {
    
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
        
        this->editorPanel = new EditorPanel(this);
        
        this->connectSignals();
        
        this->setCentralWidget(this->editorPanel);
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
        
        
        
        this->connect(this->exitAction, SIGNAL(triggered()), this, SLOT(onExit()));
        
        this->connect(this->undoAction, SIGNAL(triggered()), this, SLOT(onUndo()));
        this->connect(this->redoAction, SIGNAL(triggered()), this, SLOT(onRedo()));
        this->connect(this->cutAction, SIGNAL(triggered()), this, SLOT(onCut()));
        this->connect(this->copyAction, SIGNAL(triggered()), this, SLOT(onCopy()));
        this->connect(this->pasteAction, SIGNAL(triggered()), this, SLOT(onPaste()));
        
        QObject::connect(this->editorPanel, &EditorPanel::editorChanged, [this]() {
            this->updateTitle();
        });
        
        
        QObject::connect(this->saveAsFileAction, &QAction::triggered, [this]() {
            if (this->editorPanel->getActiveEditor()) {
                this->onSaveFileAs(this->editorPanel->getActiveEditor());
            }
        });
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
        
    }
    
    void MainWindow::onNewFile() 
    {
        SourceEditor *editor = new SourceEditorGeneric(this);
        
        this->editorPanel->openEditor(editor);
        this->editorPanel->activateEditor(editor);
        
        /*
        SourceEditor *editor = this->editorPanel->getActiveEditor();
        
        if (!editor) {
            return;
        }
        
        if (editor->getProjectItem()->isModified()) {
            switch (this->askSaveChanges()) {
                case QMessageBox::Save:
                    if (!this->onSaveFile()) {
                        return;
                    }
                
                case QMessageBox::Cancel:
                    return;
            }
        }
        
        editor->new_();
        */
    }
    
    bool MainWindow::onOpenFile() 
    {   
        // Open the file
        QString path = QFileDialog::getOpenFileName(this, "Open", QString(), tr(fileFilter));
        
        if (path.isEmpty()) {
            return false;
        }
        
        SourceEditor *editor = this->editorPanel->findNewEditor();
        
        if (!editor) {
            editor = new SourceEditorGeneric(this);
            this->editorPanel->openEditor(editor);
        }
        
        this->editorPanel->activateEditor(editor);
        editor->load(path);
        
        return true;
    }
    
    bool MainWindow::onSaveFile() 
    {
        SourceEditor *editor = this->editorPanel->getActiveEditor();
        
        if (!editor) {
            return false;
        }
        
        bool result = false;
        
        if (editor->getProjectItem()->hasPath()) {
            editor->save();
            
            result = true;
        } else {
            result = this->onSaveFileAs(editor);
        }
        
        return result;
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
    
    bool MainWindow::onSaveFileAs(SourceEditor *editor) 
    {
        QString defaultPath;
        
        if (editor->getProjectItem()->hasPath()) {
            defaultPath = QString::fromStdString(editor->getProjectItem()->getPath());
        } else {
            defaultPath = editor->getFileTitle();
        }
        
        QString path = QFileDialog::getSaveFileName(this, "Save", defaultPath, tr(fileFilter));
        
        if (path.isEmpty()) {
            return false;
        }
        
        editor->save(path);
        
        return true;
    }
    
    void MainWindow::closeEvent(QCloseEvent *event) 
    {
        SourceEditor *editor = this->editorPanel->getActiveEditor();
        
        if (!editor || !editor->getProjectItem()->isModified()) {
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
        if (!this->editorPanel->getActiveEditor()) {
            return;
        }
        
        this->editorPanel->getActiveEditor()->undo();
    }
    
    void MainWindow::onRedo()
    {
        if (!this->editorPanel->getActiveEditor()) {
            return;
        }
        
        this->editorPanel->getActiveEditor()->redo();
    }
    
    void MainWindow::onCut()
    {
        if (!this->editorPanel->getActiveEditor()) {
            return;
        }
        
        this->editorPanel->getActiveEditor()->cut();
    }
    
    void MainWindow::onCopy()
    {
        if (!this->editorPanel->getActiveEditor()) {
            return;
        }
        
        this->editorPanel->getActiveEditor()->copy();
    }
    
    void MainWindow::onPaste()
    {
        if (!this->editorPanel->getActiveEditor()) {
            return;
        }
        
        this->editorPanel->getActiveEditor()->paste();
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
    
    void MainWindow::updateTitle()
    {
        QString title;
        SourceEditor *editor = this->editorPanel->getActiveEditor();
        
        if (editor) {
            title = "felide - " + editor->getTitle();
        } else {
            title = "felide";
        }
        
        this->setWindowTitle(title);
        this->updateEditorMargin();
    }
}}
