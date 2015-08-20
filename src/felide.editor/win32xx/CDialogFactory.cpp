
#include "CDialogFactory.hpp"

#include <Windows.h>

namespace felide { namespace editor { namespace win32xx {

	class CMessageBoxDialog : public Dialog {
	public:
		explicit CMessageBoxDialog(const std::string &title, const std::string &msg, DialogIcon icons, DialogButton buttons) {

			UINT flags = MB_OK;

			switch (icons) {
				case DialogIcon::Information:	flags |= MB_ICONINFORMATION;	break;
				case DialogIcon::Warning:		flags |= MB_ICONWARNING;		break;
				case DialogIcon::Error:			flags |= MB_ICONERROR;			break;
			}

			int result = ::MessageBox(NULL, title.c_str(), msg.c_str(), MB_OK | flags);

			switch (result) {
				case IDOK:		this->result = DialogResult::Ok;		break;
				case IDCANCEL:	this->result = DialogResult::Cancel;	break;
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

	CDialogFactory::~CDialogFactory() {}

	DialogPtr CDialogFactory::showMessageDialog(const std::string &title, const std::string &msg, DialogIcon icons, DialogButton buttons) const {

		DialogPtr dialog = std::make_unique<CMessageBoxDialog>(DialogResult::Ok);

		return dialog;
	}

	DialogPtr CDialogFactory::showInputDialog(const std::string &title, const std::string &msg) const {
		DialogPtr dialog;
		return dialog;
	}
}}}