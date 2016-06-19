#include "QWorkspaceModel.hpp"


namespace felide { namespace view { namespace qt5 {

    QWorkspaceModel::QWorkspaceModel(Workspace *workspace) {
        this->workspace = workspace;
    }
    
    QVariant QWorkspaceModel::data(const QModelIndex &index, int role) const
    {
        return QVariant();
    }
    
    Qt::ItemFlags QWorkspaceModel::flags(const QModelIndex &index) const
    {
        return Qt::ItemFlags::enum_type::ItemIsEnabled;
    }
    
    QVariant QWorkspaceModel::headerData(int section, Qt::Orientation orientation, int role) const
    {
        return QVariant();
    }
    
    QModelIndex QWorkspaceModel::index(int row, int column, const QModelIndex &parent) const
    {
        return QModelIndex();
    }
    
    QModelIndex QWorkspaceModel::parent(const QModelIndex &index) const
    {
        return index;
    }
    
    int QWorkspaceModel::rowCount(const QModelIndex &parent) const
    {
        return 0;
    }
    
    int QWorkspaceModel::columnCount(const QModelIndex &parent) const
    {
        return 0;
    }
    
}}}
