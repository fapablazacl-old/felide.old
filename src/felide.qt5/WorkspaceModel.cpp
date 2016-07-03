
#include "WorkspaceModel.hpp"

namespace felide { namespace view { namespace qt5 {

    WorkspaceModel::WorkspaceModel(Workspace *workspace) {
        m_workspace = workspace;
    }
    
    QVariant WorkspaceModel::data(const QModelIndex &index, int role) const
    {
        return QVariant();
    }
    
    Qt::ItemFlags WorkspaceModel::flags(const QModelIndex &index) const
    {
        return Qt::ItemFlags::enum_type::ItemIsEnabled;
    }
    
    QVariant WorkspaceModel::headerData(int section, Qt::Orientation orientation, int role) const
    {
        return QVariant();
    }
    
    QModelIndex WorkspaceModel::index(int row, int column, const QModelIndex &parent) const
    {
        return QModelIndex();
    }
    
    QModelIndex WorkspaceModel::parent(const QModelIndex &index) const
    {
        return index;
    }
    
    int WorkspaceModel::rowCount(const QModelIndex &parent) const
    {
        return 0;
    }
    
    int WorkspaceModel::columnCount(const QModelIndex &parent) const
    {
        return 0;
    }
    
}}}
