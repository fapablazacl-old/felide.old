
#ifndef __TREE_ITEM_HPP__
#define __TREE_ITEM_HPP__

#include <list>
#include <memory>

#include <QList>
#include <QVariant>

class TreeItem {
public:
    TreeItem( const QList<QVariant> &data, TreeItem *parent);
    ~TreeItem();
    
    TreeItem* appendChild();
    TreeItem* child(int row);
    int childCount() const;
    
    int columnCount() const;
    
    QVariant data(int column) const;
    
    int row() const;
    
    TreeItem* parent();
    
    const TreeItem* parent() const;
    
private:
    QList<QVariant> itemData;
    
    std::list<std::unique_ptr<TreeItem>> childItems;
    TreeItem *parentItem = nullptr;
};


#endif  // __TREE_ITEM_HPP__
