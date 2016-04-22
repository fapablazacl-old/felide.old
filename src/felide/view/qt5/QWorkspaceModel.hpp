
#pragma once

#ifndef QWORKSPACEMODEL_HPP
#define QWORKSPACEMODEL_HPP

#include <QObject>
#include <QAbstractItemModel>

#include "felide/Workspace.hpp"

namespace felide { namespace editor { namespace qt5 {
    
    class QWorkspaceModel : public QAbstractItemModel {
        Q_OBJECT
    public:
        explicit QWorkspaceModel(Workspace *workspace);
        
        virtual QVariant data(const QModelIndex &index, int role) const override;
        virtual Qt::ItemFlags flags(const QModelIndex &index) const override;
        virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
        virtual QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
        virtual QModelIndex parent(const QModelIndex &index) const override;
        virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
        virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;
        
        
    private:
        Workspace *workspace = nullptr;
        
    signals:
        
    public slots:
    };

}}}

#endif // QWORKSPACEMODEL_HPP
