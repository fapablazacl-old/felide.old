
#include "ProjectBrowser.hpp"

#include <QVBoxLayout>
#include <QBoxLayout>

namespace felide {
    ProjectBrowser::ProjectBrowser (QWidget *parent) 
        : QWidget(parent) {

        m_treeView = new QTreeView(this);

        m_fileSystemModel = new QFileSystemModel(this);
        m_fileSystemModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
        m_fileSystemModel->setRootPath("C:/");

        m_treeView->setModel(m_fileSystemModel);

        this->setLayout(new QVBoxLayout(this));

        this->layout()->addWidget(m_treeView);
    }

    ProjectBrowser::~ProjectBrowser() {}
}
