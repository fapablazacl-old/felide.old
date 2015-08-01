
#include "MainFrame.hpp"
#include "res/resource.h"

#include <file.h>
#include <string>

namespace felide { namespace editor { namespace win32xx {

    MainFrame::MainFrame() {
        this->projectItem = std::make_unique<ProjectItem>();

        this->textEditor = CodeEdit::new_();
        this->SetView(*this->textEditor.get());
    }

    MainFrame::~MainFrame() {}

    void MainFrame::OnDestroy() {
        ::PostQuitMessage(0);
    }

    void MainFrame::OnInitialUpdate() {
        this->SetWindowTextA("Felide Editor");
    }

    BOOL MainFrame::OnCommand(WPARAM wParam, LPARAM lParam) {
        const int command = LOWORD(wParam);

        switch (command) {
            case ID_FILE_NEW:       this->OnFileNew();      return TRUE;
            case ID_FILE_OPEN:      this->OnFileOpen();     return TRUE;
            case ID_FILE_SAVE:      this->OnFileSave();     return TRUE;
            case ID_FILE_SAVEAS:    this->OnFileSaveAs();   return TRUE;
            case ID_FILE_EXIT:      this->OnFileExit();     return TRUE;
            default: return FALSE;
        }
    }

    bool MainFrame::checkSavedChanges() {
        if (this->projectItem->isModified()) {
            int result = MessageBox("Do you want to save the changes?", "Felide", MB_YESNOCANCEL | MB_ICONQUESTION);

            switch (result) {
                case 0: 
                    this->SendMessage(WM_COMMAND, ID_FILE_SAVE, 0); 
                    return true;

                case 1: return true;
                case 2: return false;
            }
        }

        return true;
    }

    void MainFrame::OnFileNew() {
        if (!this->checkSavedChanges()) {
            return;
        }

        this->projectItem = std::make_unique<ProjectItem>();

        this->textEditor->ClearAll();
        this->textEditor->EmptyUndoBuffer();
    }

    void MainFrame::OnFileOpen() {
        CString filePath = CFile().OpenFileDialog(nullptr, 6UL, nullptr, "C/C++ Files\0*.c;*.cpp");
                
        if (filePath == "") {
            return;
        }

        this->SendMessage(WM_COMMAND, ID_FILE_NEW, 0);

        std::string content = this->projectItem->open(filePath.c_str());

        this->textEditor->SetText(content.c_str());
        this->textEditor->EmptyUndoBuffer();
        this->textEditor->SetSavePoint();
    }

    void MainFrame::OnFileSave() {
        if (!this->projectItem->hasPath()) {
            this->SendMessage(WM_COMMAND, ID_FILE_SAVEAS, 0);
            return;
        }

        std::string content = this->textEditor->GetText().c_str();
        this->projectItem->save(content);
    }

    void MainFrame::OnFileSaveAs() {
        CString filePath = CFile().SaveFileDialog(nullptr, 6UL, nullptr, "C/C++ Files\0*.c;*.cpp");

        if (filePath == "") {
            return;
        }

        std::string content = this->textEditor->GetText().c_str();
        this->projectItem->save(content, filePath.c_str());
    }

    void MainFrame::OnFileExit() {
        if (!this->checkSavedChanges()) {
            return;
        }

        this->Close();
    }
}}}
