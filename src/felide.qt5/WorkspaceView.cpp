
#include "WorkspaceView.hpp"

namespace felide { namespace view { namespace qt5 {

    WorkspaceView::WorkspaceView(QWidget *parent, Workspace *workspace) : QWidget(parent) {
        
        this->setWorkspace(workspace);
    }
    
    void WorkspaceView::setWorkspace(Workspace *workspace) {
        m_workspace = workspace;
    }
    
}}}
