
#include "QWorkspaceView.hpp"

namespace felide { namespace view { namespace qt5 {

    QWorkspaceWidget::QWorkspaceWidget(QWidget *parent, Workspace *workspace) : QWidget(parent) {
        
        this->setWorkspace(workspace);
    }
    
    void QWorkspaceWidget::setWorkspace(Workspace *workspace) {
        this->workspace = workspace;
    }
    
}}}
