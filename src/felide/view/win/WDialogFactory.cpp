
#include "WDialogFactory.hpp"
#include <wcl/FileDialog.hpp>

namespace felide { namespace view { namespace win {

	class WMessageDialog : public Dialog {
	public:
		WMessageDialog(const std::string &title, const std::string &msg, DialogIcon icons, DialogButton buttons) {
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

			std::wstring wmsg(msg.begin(), msg.end());
			std::wstring wtitle(title.begin(), title.end());

			m_result = ::MessageBox(NULL, wmsg.c_str(), wtitle.c_str(), flags);
		}

		DialogResult getResult() const override {
			switch (m_result) {
				case IDOK:		return DialogResult::Ok;
				case IDCANCEL:	return DialogResult::Cancel;
				case IDYES:		return DialogResult::Yes;
				case IDNO:		return DialogResult::No;
			}
		}

		DialogData getData() const override {
			return DialogData();
		}

		DialogDataList getDataList() const override {
			return DialogDataList();
		}

	private:
		int m_result = 0;
	};

	enum class WFileDialogType {
		Open, Save
	};

	class WFileDialog : public Dialog {
	public:
		explicit WFileDialog(const std::string &title, const std::string &filters, WFileDialogType type) {
			std::wstring filePath;

			std::wstring wtitle(title.begin(), title.end());
			std::wstring wfilters(filters.begin(), filters.end());
			wcl::FileDialog fileDialog(wtitle, wfilters);

			switch (type) {
				case WFileDialogType::Open: fileDialog.ShowOpen(); break;
				case WFileDialogType::Save: fileDialog.ShowSave(); break;
			}

			m_result = fileDialog.UserCancel()?DialogResult::Cancel:DialogResult::Ok;

			if (fileDialog.UserCancel()) {
				m_file = boost::filesystem::path();
			} else {
				m_file = fileDialog.GetFileName();
			}
		}

		virtual DialogResult getResult() const override {
			return m_result;
		}

		virtual DialogData getData() const override {
			return DialogData(m_file);
		}

		virtual DialogDataList getDataList() const override {
			return DialogDataList();
		}

	private:
		DialogResult m_result = DialogResult::Cancel;
		boost::filesystem::path m_file;
	};

	DialogPtr WDialogFactory::showMessageDialog(const std::string &title, const std::string &msg, DialogIcon icons, DialogButton buttons) const {
		return std::make_unique<WMessageDialog>(title, msg, icons, buttons);
	}

	DialogPtr WDialogFactory::showInputDialog(const std::string &title, const std::string &msg) const {
		return DialogPtr();
	}

	DialogPtr WDialogFactory::showFileOpenDialog(const std::string &title, const std::string &filters) const {
		return std::make_unique<WFileDialog>(title, filters, WFileDialogType::Open);
	}
		
	DialogPtr WDialogFactory::showFileSaveDialog(const std::string &title, const std::string &filters) const {
		return std::make_unique<WFileDialog>(title, filters, WFileDialogType::Save);
	}
}}}
