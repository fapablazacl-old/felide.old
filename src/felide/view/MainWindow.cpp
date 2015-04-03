
#include "MainWindow.hpp"

#include <sstream>
#include <iostream>

#include <QFileDialog>
#include <QCloseEvent>
#include <QMessageBox>

#include <felide/view/EditorGeneric.hpp>

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
        QObject::connect(this->newFileAction, &QAction::triggered, [this](){
            this->onNewFile();
        });
        
        QObject::connect(this->openFileAction, &QAction::triggered, [this](){
           this->onOpenFile();
        });
                
        QObject::connect(this->saveFileAction, &QAction::triggered, [this](){
            Editor *editor = this->editorPanel->getActiveEditor();
            
            if (editor) {
                this->onSaveFile(editor);
            }
        });
                         
        QObject::connect(this->saveAsFileAction, &QAction::triggered, [this](){
            Editor *editor = this->editorPanel->getActiveEditor();
            
            if (editor) {
                this->onSaveFileAs(editor);
            }
        });
        
        this->connect(this->exitAction, SIGNAL(triggered()), this, SLOT(onExit()));
        
        QObject::connect(this->undoAction, &QAction::triggered, [this]() {
            Editor *editor = this->editorPanel->getActiveEditor();
            
            if (editor) {
                this->onUndo(editor);
            }
        });
        
        QObject::connect(this->redoAction, &QAction::triggered, [this]() {
            Editor *editor = this->editorPanel->getActiveEditor();
            
            if (editor) {
                this->onRedo(editor);
            }
        });
        
        QObject::connect(this->cutAction, &QAction::triggered, [this]() {
            Editor *editor = this->editorPanel->getActiveEditor();
            
            if (editor) {
                this->onCut(editor);
            }
        });
        
        QObject::connect(this->copyAction, &QAction::triggered, [this]() {
            Editor *editor = this->editorPanel->getActiveEditor();
            
            if (editor) {
                this->onCopy(editor);
            }
        });
        
        QObject::connect(this->pasteAction, &QAction::triggered, [this]() {
            Editor *editor = this->editorPanel->getActiveEditor();
            
            if (editor) {
                this->onPaste(editor);
            }
        });
        
        
        QObject::connect(this->editorPanel, &EditorPanel::editorChanged, [this]() {
            this->updateTitle();
        });
        
        QObject::connect(this->editorPanel, &EditorPanel::editorClosed, [this](Editor *editor) {
            if (this->saveChanges(editor)) {
                this->editorPanel->closeEditor(editor);
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
    
    void MainWindow::onNewFile() 
    {
        Editor *editor = new EditorGeneric(this);
        
        this->editorPanel->openEditor(editor);
        this->editorPanel->activateEditor(editor);
    }
    
    bool MainWindow::onOpenFile() 
    {   
        // Open the file
        QString path = QFileDialog::getOpenFileName(this, "Open", QString(), tr(fileFilter));
        
        if (path.isEmpty()) {
            return false;
        }
        
        Editor *editor = this->editorPanel->findNewEditor();
        
        if (!editor) {
            editor = new EditorGeneric(this);
            this->editorPanel->openEditor(editor);
        }
        
        this->editorPanel->activateEditor(editor);
        editor->load(path);
        
        return true;
    }
    
    bool MainWindow::onSaveFile(Editor *editor) 
    {
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
    
    int MainWindow::askSaveChanges(Editor *editor) 
    {
        QMessageBox msgBox;
        msgBox.setText("The file '" + editor->getFileTitle() + " has been modified.");
        msgBox.setInformativeText("Do you want to save your changes?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        
        return msgBox.exec();
    }
    
    bool MainWindow::onSaveFileAs(Editor *editor) 
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
        Editor *editor = this->editorPanel->getActiveEditor();
        
        if (this->saveChanges(editor)) {
            event->accept();
        } else {
            event->ignore();
        }
    }
    
    void MainWindow::onExit() 
    {
        this->close();
    }
    
    void MainWindow::onUndo(Editor *editor) 
    {
        editor->undo();
    }
    
    void MainWindow::onRedo(Editor *editor)
    {
        editor->redo();
    }
    
    void MainWindow::onCut(Editor *editor)
    {
        editor->cut();
    }
    
    void MainWindow::onCopy(Editor *editor)
    {
        editor->copy();
    }
    
    void MainWindow::onPaste(Editor *editor)
    {
        editor->paste();
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
        Editor *editor = this->editorPanel->getActiveEditor();
        
        if (editor) {
            title = "felide - " + editor->getTitle();
        } else {
            title = "felide";
        }
        
        this->setWindowTitle(title);
        this->updateEditorMargin();
    }
    
    
    bool MainWindow::onClose(Editor *editor) { }
    
    bool MainWindow::saveChanges(Editor *editor)
    {
        if (!editor || !editor->getProjectItem()->isModified()) {
            return true;
        }
        
        switch (this->askSaveChanges(editor)) {
            case QMessageBox::Save:     return this->onSaveFile(editor);
            case QMessageBox::Discard:  return true;
            case QMessageBox::Cancel:   return false;
        }
    }
}}
