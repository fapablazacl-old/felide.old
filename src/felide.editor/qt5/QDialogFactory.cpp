
#include "QDialogFactory.hpp"

#include <QMessageBox>
#include <QFileDialog>

namespace felide { namespace editor { namespace qt5 {
    
    class QMessageBoxDialog : public Dialog {
    public:
        QMessageBoxDialog(const std::string &title, const std::string &msg, DialogIcon icons, DialogButton buttons) {
            int result = 0;
            
            // Icon
            if (icons == DialogIcon::Information) {
                result = QMessageBox::information(nullptr, title.c_str(), msg.c_str());
                
            } else if (icons == DialogIcon::Warning) {
                result = QMessageBox::warning(nullptr, title.c_str(), msg.c_str());
                
            } else if (icons == DialogIcon::Error) {
                result = QMessageBox::critical(nullptr, title.c_str(), msg.c_str());
                
            } else {
                
            }
            
            // Convert result
            if (result == QMessageBox::Ok) {
                this->result = DialogResult::Ok;
                
            } else if (result == QMessageBox::Cancel) {
                this->result = DialogResult::Cancel;
            }
        }
        
        virtual DialogResult getResult() const override {
            return this->result;
        }
        
        virtual DialogData getData() const override {
            return DialogData();
        }
        
        virtual DialogDataList getDataList() const override {
            return DialogDataList();
        }
        
    private:
        DialogResult result;
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
            
            this->result = path!="" ? DialogResult::Ok : DialogResult::Cancel;
            this->file = path.toStdString();
        }
        
        virtual DialogResult getResult() const override {
            return this->result;
        }
        
        virtual DialogData getData() const override {
            return DialogData(this->file);
        }
        
        virtual DialogDataList getDataList() const override {
            DialogDataList dataList = {
                DialogData(this->file)
            };
            
            return dataList;
        }
        
    private: 
        DialogResult result;
        boost::filesystem::path file;
    };
    
    DialogPtr QDialogFactory::showMessageDialog(const std::string &title, const std::string &msg, DialogIcon icons, DialogButton buttons) const {
        return std::make_unique<QMessageBoxDialog>(title, msg, icons, buttons);
    }
    
    DialogPtr QDialogFactory::showInputDialog(const std::string &title, const std::string &msg) const {
        return DialogPtr();
    }
    
    DialogPtr QDialogFactory::showFileOpenDialog(const std::string &title, const std::string &filters) const {
        return std::make_unique<QFileDialog>(title, filters, QFileDialogType::Open);
    }
    
	DialogPtr QDialogFactory::showFileSaveDialog(const std::string &title, const std::string &filters) const {
        return std::make_unique<QFileDialog>(title, filters, QFileDialogType::Save);
    }
}}}
