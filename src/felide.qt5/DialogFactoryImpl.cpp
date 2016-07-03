
#include "DialogFactoryImpl.hpp"

#include <QMessageBox>
#include <QFileDialog>

namespace felide { namespace view { namespace qt5 {
    
    class QMessageBoxDialog : public Dialog {
    public:
        QMessageBoxDialog(const std::string &title, const std::string &msg, DialogIcon icons, DialogButton buttons) {
            int result = 0;
            
            // Buttons
            QMessageBox::StandardButtons qbuttons;
            
            if (buttons == DialogButton::Ok) {
                qbuttons = QMessageBox::Ok;
                
            } else if (buttons == DialogButton::OkCancel) {
                qbuttons = QMessageBox::Ok | QMessageBox::Cancel;
                
            } else if (buttons == DialogButton::YesNoCancel) {
                qbuttons = QMessageBox::Yes |  QMessageBox::No | QMessageBox::Cancel;
                
            } else {
                assert(false);
            }
            
            // Icon
            if (icons == DialogIcon::Information) {
                result = QMessageBox::information(nullptr, title.c_str(), msg.c_str(), qbuttons);
                
            } else if (icons == DialogIcon::Warning) {
                result = QMessageBox::warning(nullptr, title.c_str(), msg.c_str(), qbuttons);
                
            } else if (icons == DialogIcon::Error) {
                result = QMessageBox::critical(nullptr, title.c_str(), msg.c_str(), qbuttons);
                
            } else if (icons == DialogIcon::Question) {
                result = QMessageBox::question(nullptr, title.c_str(), msg.c_str(), qbuttons);
                
            } else {
                assert(false);
            }
            
            // Convert result
            if (result == QMessageBox::Ok) {
                m_result = DialogResult::Ok;
                
            } else if (result == QMessageBox::Cancel) {
                m_result = DialogResult::Cancel;
                
            } else if (result == QMessageBox::Yes) {
                m_result = DialogResult::Yes;
                
            } else if (result == QMessageBox::No) {
                m_result = DialogResult::No;
                
            }
        }
        
        virtual DialogResult getResult() const override {
            return m_result;
        }
        
        virtual DialogData getData() const override {
            return DialogData();
        }
        
        virtual DialogDataList getDataList() const override {
            return DialogDataList();
        }
        
    private:
        DialogResult m_result;
    };
    
    enum class QFileDialogType {
        Open,
        Save
    };
    
    class QFileDialog : public Dialog {
    public:
        QFileDialog(const std::string &title, const std::string &filters, QFileDialogType dialogType) {
            QString path = "";
            
            switch (dialogType) {
                case QFileDialogType::Open:
                    path = ::QFileDialog::getOpenFileName(nullptr, title.c_str(), "", "(*.cpp)");
                    break;
                
                case QFileDialogType::Save:
                    path = ::QFileDialog::getSaveFileName(nullptr, title.c_str(), "", "(*.cpp)");
                    break;
            }
            
            m_result = path!="" ? DialogResult::Ok : DialogResult::Cancel;
            m_file = path.toStdString();
        }
        
        virtual DialogResult getResult() const override {
            return m_result;
        }
        
        virtual DialogData getData() const override {
            return DialogData(m_file);
        }
        
        virtual DialogDataList getDataList() const override {
            DialogDataList dataList = {
                DialogData(m_file)
            };
            
            return dataList;
        }
        
    private: 
        DialogResult m_result;
        boost::filesystem::path m_file;
    };
    
    DialogPtr DialogFactoryImpl::showMessageDialog(const std::string &title, const std::string &msg, DialogIcon icons, DialogButton buttons) const {
        return std::make_unique<QMessageBoxDialog>(title, msg, icons, buttons);
    }
    
    DialogPtr DialogFactoryImpl::showInputDialog(const std::string &title, const std::string &msg) const {
        return DialogPtr();
    }
    
    DialogPtr DialogFactoryImpl::showFileOpenDialog(const std::string &title, const std::string &filters) const {
        return std::make_unique<QFileDialog>(title, filters, QFileDialogType::Open);
    }
    
	DialogPtr DialogFactoryImpl::showFileSaveDialog(const std::string &title, const std::string &filters) const {
        return std::make_unique<QFileDialog>(title, filters, QFileDialogType::Save);
    }
}}}
