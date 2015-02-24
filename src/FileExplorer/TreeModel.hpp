
#ifndef __TREE_MODEL_HPP__
#define __TREE_MODEL_HPP__

#include <QAbstractItemModel>
#include <memory>

#include "TreeItem.hpp"

class TreeModel : public QAbstractItemModel 
{
    Q_OBJECT
    
public:
    TreeModel(QObject *parent);
    ~TreeModel();
    
    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    
    QVariant headerData(int section, Qt::Orientation orientation, int role=Qt::DisplayRole) const;
    
    QModelIndex index(int row, int column, const QModelIndex& parent=QModelIndex()) const;
    
    QModelIndex parent(const QModelIndex &index) const;
    
    int rowCount(const QModelIndex &parent=QModelIndex()) const;
    int columnCount(const QModelIndex &parent=QModelIndex()) const;
    
private:
    void setupModelData();
    std::unique_ptr<TreeItem> rootItem;
};

#endif  //__TREE_MODEL_HPP__
