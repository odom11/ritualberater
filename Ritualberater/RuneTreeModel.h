#pragma once
#include <memory>

#include <QModelIndex>
#include <QVariant>

#include "AbstractRuneNode.h"
#include "RuneLeaf.h"
class RuneTreeModel : public QAbstractItemModel {
    Q_OBJECT

public:
    explicit RuneTreeModel(const QString& data, QObject* parent = nullptr);

    QVariant data(const QModelIndex& index, int role) const override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
        int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex& index, const QVariant& value,
        int role = Qt::EditRole) override;
    QModelIndex index(int row, int column,
        const QModelIndex& parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex& index) const override;
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;

private:
    void initializeRuneTree();
    RuneLeaf* getRuneleafPointer(QModelIndex index) const;
    std::unique_ptr<AbstractRuneNode> root;
    //void setupModelData(const QStringList& lines, TreeItem* parent);

    //TreeItem* rootItem;
};