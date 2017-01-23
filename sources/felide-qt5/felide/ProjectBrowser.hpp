
#pragma once

#ifndef __felide_projectbrowser_hpp__
#define __felide_projectbrowser_hpp__

#include <QWidget>
#include <QDockWidget>
#include <QTreeView>
#include <QFileSystemModel>

namespace felide {
    class ProjectBrowser : public QWidget {
        Q_OBJECT

    public:
        ProjectBrowser(QWidget *parent);

        ~ProjectBrowser();

    private:
        QTreeView *m_treeView = nullptr;
        QFileSystemModel *m_fileSystemModel = nullptr;
    };
}

#endif
