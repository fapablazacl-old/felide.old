#include <QApplication>
#include <QTreeView>

#include "FileExplorer.hpp"
#include "TreeModel.hpp"

FileExplorer::FileExplorer(QWidget* parent, Qt::WindowFlags flags) : QMainWindow(parent, flags) 
{
    this->tableView = new QTableView(this);
    this->setCentralWidget(this->tableView);
}

FileExplorer::~FileExplorer()  {}

int main(int argc, char **argv) 
{
    QApplication app(argc, argv);
    
    
    QTreeView treeView;
    TreeModel treeModel(nullptr);
    treeView.setModel(&treeModel);
    treeView.show();
    
    return app.exec();
}
