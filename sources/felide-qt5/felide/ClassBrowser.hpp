
#pragma once

#ifndef __felide_classbrowser_hpp__
#define __felide_classbrowser_hpp__

#include <QWidget>
#include <QDockWidget>
#include <QTreeView>
#include <QFileSystemModel>

namespace felide {
    class ClassBrowser : public QWidget {
        Q_OBJECT

    public:
        ClassBrowser(QWidget *parent);

        ~ClassBrowser();

    private:
        QTreeView *m_treeView = nullptr;
    };
}

#endif
