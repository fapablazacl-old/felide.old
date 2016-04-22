#include "QWorkspaceModel.hpp"


namespace felide { namespace editor { namespace qt5 {

    QWorkspaceModel::QWorkspaceModel(Workspace *workspace) {
        this->workspace = workspace;
    }
    
    QVariant QWorkspaceModel::data(const QModelIndex &index, int role) const
    {
        
    }
    
    Qt::ItemFlags QWorkspaceModel::flags(const QModelIndex &index) const
    {
        
    }
    
    QVariant QWorkspaceModel::headerData(int section, Qt::Orientation orientation, int role) const
    {
        
    }
    
    QModelIndex QWorkspaceModel::index(int row, int column, const QModelIndex &parent) const
    {
        
    }
    
    QModelIndex QWorkspaceModel::parent(const QModelIndex &index) const
    {
        
    }
    
    int QWorkspaceModel::rowCount(const QModelIndex &parent) const
    {
        
    }
    
    int QWorkspaceModel::columnCount(const QModelIndex &parent) const
    {
        
    }
    
}}}
