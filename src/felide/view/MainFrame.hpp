
#ifndef __felide_editor_mainframe_hpp__
#define __felide_editor_mainframe_hpp__

#include "felide/view/View.hpp"
#include "felide/view/Editor.hpp"

#include "MainFrameHandler.hpp"
#include <vector>

namespace felide {
    class App;
}

namespace felide { namespace view {
	class MainFrameHandler;
	class MainFrame : public View<MainFrameHandler> {
	public:
		MainFrame();
		virtual ~MainFrame();

        virtual App* getApp() = 0;
        virtual const App* getApp() const = 0;
        
		virtual Editor* createEditor(ProjectItemPtr item) = 0;
		virtual void closeEditor(Editor* view) = 0;

		virtual Editor* getCurrentEditor() = 0;
		virtual const Editor* getCurrentEditor() const = 0;

		virtual int getEditorCount() const = 0;
		virtual Editor* getEditor(const int index) = 0;
		virtual const Editor* getEditor(const int index) const = 0;
		
		virtual void setEditorTitle(Editor *view, const std::string &title) = 0;
		virtual std::string getEditorTitle(Editor *view) const = 0;
		
		virtual void close() = 0;

		virtual void updateEnableStatus() = 0;

		/**
		 * @brief Get a Vector containing all the available editors, by value.
		 */
		std::vector<Editor*> getEditors() {
			std::vector<Editor*> editors(this->getEditorCount());

			for (int i=0; i<this->getEditorCount(); i++) {
				editors[i] = this->getEditor(i);
			}

			return editors;
		}

		std::vector<const Editor*> getEditors() const {
			std::vector<const Editor*> editors(this->getEditorCount());

			for (int i=0; i<this->getEditorCount(); i++) {
				editors[i] = this->getEditor(i);
			}

			return editors;
		}
	};
}}

#endif // __felide_editor_mainframe_hpp__
