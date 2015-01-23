
#ifndef __FILE_EXPLORER_HPP__
#define __FILE_EXPLORER_HPP__

#include <memory>
#include <QMainWindow>
#include <QTreeView>
#include <QTableView>

class FileExplorer : public QMainWindow 
{
    Q_OBJECT
    
public:
    FileExplorer(QWidget* parent, Qt::WindowFlags flags);
    
    virtual ~FileExplorer();
    
private:
    QTableView *tableView = nullptr;
};

#endif  // __FILE_EXPLORER_HPP__
