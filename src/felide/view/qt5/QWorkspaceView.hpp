
#pragma once

#ifndef QWORKSPACEWIDGET_HPP
#define QWORKSPACEWIDGET_HPP

#include <QWidget>
#include <QTreeView>

#include "felide/Workspace.hpp"

namespace felide { namespace view { namespace qt5 {

    class QWorkspaceWidget : public QWidget {
        Q_OBJECT
    public:
        QWorkspaceWidget(QWidget *parent = nullptr, Workspace *workspace = nullptr);
        
        void setWorkspace(Workspace *workspace);
        
        Workspace* getWorkspace() {
            return workspace;
        }

        const Workspace* getWorkspace() const {
            return workspace;
        }
        
    signals:
        
    public slots:
        
    private:
        Workspace *workspace = nullptr;
        QTreeView *treeView = nullptr;
    };
}}}

#endif // QWORKSPACEWIDGET_HPP
