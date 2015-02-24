
#include "TreeItem.hpp"

TreeItem::TreeItem( const QList<QVariant> &data, TreeItem *parentItem)
{
    this->parentItem = parentItem;
    this->itemData = data;
}

TreeItem::~TreeItem() {}

TreeItem* TreeItem::appendChild() 
{
    QList<QVariant> tmp;
    
    auto item = std::unique_ptr<TreeItem>(new TreeItem(tmp, this));
    this->childItems.push_back(std::move(item));
    
    return item.get();
}

TreeItem* TreeItem::child(int row) 
{
    auto pos = std::begin(this->childItems);
    std::advance(pos, row);
    
    return pos->get();
}

int TreeItem::childCount() const 
{
    return this->childItems.size();
}


int TreeItem::columnCount() const
{
    return this->itemData.count();
}

QVariant TreeItem::data(int column) const 
{
    return this->itemData.value(column);
}

int TreeItem::row() const 
{
    if (this->parentItem) {
        int pos = 0;
        
        for (auto &treeItem : this->parentItem->childItems) {
            if (treeItem.get() == this) {
                break;
            }
            
            pos++;
        }
       
        return pos;
    }
    
    return 0;
}

TreeItem* TreeItem::parent() 
{
    return this->parentItem;
    
}

const TreeItem* TreeItem::parent() const 
{
    return this->parentItem;
}
