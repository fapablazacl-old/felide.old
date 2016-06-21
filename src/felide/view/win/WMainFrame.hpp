
#pragma once

#ifndef __mainframe_hpp__
#define __mainframe_hpp__

#include <wcl/wcl.hpp>
#include <wcl/TreeView.hpp>
#include <wcl/ImageList.hpp>
#include <wcl/AcceleratorTable.hpp>
#include <wcl/Scintilla.hpp>
#include <memory>

#include "AppImpl.hpp"

namespace gen {

	struct TreeViewItem {
		int image = 0;
		int selectedImage = 0;
		std::wstring text;
		std::vector<TreeViewItem> childs;

		TreeViewItem() {}
		TreeViewItem(int image_, int selectedImage_, const std::wstring &text_) : image(image_), selectedImage(selectedImage_), text(text_) {}
		TreeViewItem(int image_, int selectedImage_, const std::wstring &text_, const std::vector<TreeViewItem> &childs_) : image(image_), selectedImage(selectedImage_), text(text_), childs(std::move(childs_)) {}

		void Generate(wcl::TreeView *treeView, HTREEITEM hParent) const {

			wcl::TreeViewItemData itemData = wcl::TreeViewItemData::Create(this->text, this->image, this->selectedImage);

			HTREEITEM hItem = treeView->InsertItem(itemData, hParent, NULL);

			for (const auto &child : this->childs) {
				child.Generate(treeView, hItem);
			}
		}
	};
}


namespace felide { namespace view { namespace win {

	class WMainFrame : public wcl::Frame {
	public:
		enum {
			ID_FILE_NEW = 1000,
			ID_FILE_OPEN,
			ID_FILE_SAVE,
			ID_FILE_SAVEAS,
			ID_FILE_SAVEALL,
			ID_FILE_PRINT,
			ID_FILE_CLOSE,
			ID_FILE_CLOSEALL,
			ID_FILE_EXIT,
	
			ID_EDIT_UNDO = 2000,
			ID_EDIT_REDO,
			ID_EDIT_CUT,
			ID_EDIT_COPY,
			ID_EDIT_PASTE,
			ID_EDIT_SEARCH,
			ID_EDIT_REPLACE,
	
			ID_VIEW_PROJECT = 3000,
			ID_VIEW_CLASSVIEW,
			ID_VIEW_OUTPUT,
			ID_VIEW_RESOURCEEDITOR,
			ID_VIEW_LOG,
	
			ID_PROJECT_MAKE = 4000,
			ID_PROJECT_INSTALL,
			ID_PROJECT_CLEAN,
			ID_PROJECT_PROPERTIES,
	
			ID_DEBUG_START = 5000,
			ID_DEBUG_RESUME,
			ID_DEBUG_PAUSE,
			ID_DEBUG_STOP,
			ID_DEBUG_STARTWITHOUTDEBUGGING,
			ID_DEBUG_BREAKPOINTADD,
			ID_DEBUG_BREAKPOINTREMOVE,
	
			ID_TOOLS_OPTIONS = 6000,
	
			ID_HELP_ABOUT = 7000,
		};


	public:
		explicit WMainFrame(AppImpl *app);

		void initMenuBar();

		void OnFileExit();
	
		virtual void OnClose() override;
		virtual void OnCreate() override;
		virtual void OnCommand(const int commandId) override;
		virtual void OnSize(const int width, const int height) override;
	
		wcl::AcceleratorTable* GetAcceleratorTable() {
			return m_acceleratorTable.get();
		}

		const wcl::AcceleratorTable* GetAcceleratorTable() const {
			return m_acceleratorTable.get();
		}

		// int getLexer(const std::string &ext);

	public:
		void SetFile(const std::string &filename, const std::string &content);

	private:
		wcl::MenuPtr m_menu;
		// wcl::TreeViewPtr m_treeView;
		// wcl::ImageListPtr m_imageList;
		wcl::AcceleratorTablePtr m_acceleratorTable;
		wcl::Scintilla m_textEditor;
		wcl::Sizer m_sizer;

		std::string m_filename;

		AppImpl *m_app = nullptr;
	};
}}}

#endif
