#pragma once

#include <wcl/Scintilla.hpp>

#include "felide/ProjectItem.hpp"
#include "felide/view/Editor.hpp"

namespace felide { namespace view { namespace win {

	class WEditor : public wcl::Scintilla, public Editor {
	public:
		explicit WEditor(ProjectItemPtr item);

	public:
		virtual LRESULT Procedure(UINT Msg, WPARAM wParam, LPARAM lParam);

	public:
		virtual void setText(const std::string &text) override;
		virtual std::string getText() const override;

		virtual void setSavePoint() override;
		virtual void emptyUndoBuffer() override;
		virtual void clearAll() override;
		virtual void setTabWidth(const int spaces) override;

		virtual void setFont(const std::string &name, const int size) override;

		virtual ProjectItem* getProjectItem() override;
		virtual const ProjectItem* getProjectItem() const override;

		virtual void undo() override;
		virtual void redo() override;

		virtual void cut() override;
		virtual void copy() override;
		virtual void paste() override;
		
	private:
		ProjectItemPtr m_item;
	};
}}}
