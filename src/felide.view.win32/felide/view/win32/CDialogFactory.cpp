
#include "CDialogFactory.hpp"

#include <file.h>

namespace felide { namespace editor { namespace win32xx {

	using namespace Win32xx;

	class CMessageBoxDialog : public Dialog {
	public:
		explicit CMessageBoxDialog(const std::string &title, const std::string &msg, DialogIcon icons, DialogButton buttons) {

			UINT flags = MB_OK;

			switch (icons) {
				case DialogIcon::Question:		flags |= MB_ICONQUESTION;		break;
				case DialogIcon::Information:	flags |= MB_ICONINFORMATION;	break;
				case DialogIcon::Warning:		flags |= MB_ICONWARNING;		break;
				case DialogIcon::Error:			flags |= MB_ICONERROR;			break;

				default: assert(false); break;
			}

			switch (buttons) {
				case DialogButton::YesNoCancel:		flags |= MB_YESNOCANCEL;		break;
				case DialogButton::Ok :				flags |= MB_OK;					break;
				case DialogButton::OkCancel:		flags |= MB_OKCANCEL;			break;

				default: assert(false); break;
			}

			int result = ::MessageBox(NULL, msg.c_str(), title.c_str(), flags);

			switch (result) {
				case IDOK:		this->result = DialogResult::Ok;		break;
				case IDCANCEL:	this->result = DialogResult::Cancel;	break;
				case IDYES:		this->result = DialogResult::Yes;		break;
				case IDNO:		this->result = DialogResult::No;		break;
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
		DialogResult result = DialogResult::Cancel;
	};

	enum class CFileDialogType {
		Open, Save
	};

	class CFileDialog : public Dialog {
	public:
		explicit CFileDialog(const std::string &title, CFileDialogType type) {
			CString filePath = "";

			if (type == CFileDialogType::Open) {
				filePath = CFile().OpenFileDialog(nullptr, 6UL, nullptr, "C/C++ Files\0*.c;*.cpp");
			}

			if (type == CFileDialogType::Save) {
				filePath = CFile().SaveFileDialog(nullptr, 6UL, nullptr, "C/C++ Files\0*.c;*.cpp");
			}

			this->result = filePath==""?DialogResult::Cancel:DialogResult::Ok;
			this->file = filePath.c_str();
		}

		virtual DialogResult getResult() const override {
			return this->result;
		}

		virtual DialogData getData() const override {
			return DialogData(this->file);
		}

		virtual DialogDataList getDataList() const override {
			return DialogDataList();
		}

	private:
		DialogResult result = DialogResult::Cancel;
		boost::filesystem::path file;
	};

	CDialogFactory::~CDialogFactory() {}

	DialogPtr CDialogFactory::showMessageDialog(const std::string &title, const std::string &msg, DialogIcon icons, DialogButton buttons) const {
		return std::make_unique<CMessageBoxDialog>(title, msg, icons, buttons);
	}

	DialogPtr CDialogFactory::showInputDialog(const std::string &title, const std::string &msg) const {
		DialogPtr dialog;
		return dialog;
	}

	DialogPtr CDialogFactory::showFileOpenDialog(const std::string &title, const std::string &filters) const {
		return std::make_unique<CFileDialog>(title, CFileDialogType::Open);
	}

	DialogPtr CDialogFactory::showFileSaveDialog(const std::string &title, const std::string &filters) const {
		return std::make_unique<CFileDialog>(title, CFileDialogType::Save);
	}
}}}
