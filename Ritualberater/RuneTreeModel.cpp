#include <QDebug>
#include "RuneTreeModel.h"
#include "RuneNode.h"
#include "RuneLeaf.h"

const std::string ROOT_NAME = "Runenarten";

class RootNode : public RuneNode
{
public:
    RootNode(const std::string& name, AbstractRuneNode* parent) : RuneNode(name, parent) {};
	virtual unsigned int columnCount() override
	{
        return 3;
	}
};

RuneTreeModel::RuneTreeModel(const QString& data, QObject* parent)
    : QAbstractItemModel(parent) {

    initializeRuneTree();
}

int RuneTreeModel::columnCount(const QModelIndex& parent) const {
    qDebug() << "calling column count" << parent.row() << parent.column();
    if (parent.isValid()) {
        return static_cast<AbstractRuneNode*>(parent.internalPointer())->columnCount();
    }
    return root->columnCount();
}

QVariant RuneTreeModel::data(const QModelIndex& index, int role) const {
    qDebug() << "calling data()" << index.row() << " " << index.column();
    auto row = index.row();
    auto col = index.column();
    if (!index.isValid()) {
        return QVariant();
    }

    if (role != Qt::DisplayRole) {
        return QVariant();
    }

    AbstractRuneNode* item = static_cast<AbstractRuneNode*>(index.internalPointer());

    return item->data(index.column());
}

Qt::ItemFlags RuneTreeModel::flags(const QModelIndex& index) const {
    qDebug() << "calling flags";
    if (!index.isValid() || index.column() != 2) {
        return Qt::NoItemFlags;
    }

    return Qt::ItemIsEditable | QAbstractItemModel::flags(index);
}

QVariant RuneTreeModel::headerData(int section, Qt::Orientation orientation, int role) const {
    qDebug() << "calling header data" << section;
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
	    switch (section)
	    {
        case 0:
            return QVariant("Hauptrunes");
        case 1:
            return QVariant("Kosten");
        case 2:
            return QVariant("Anzahl");
        default:
            return QVariant();
	    }
        //return root->data(section);
    }
    return QVariant();
}

QModelIndex RuneTreeModel::index(int row, int column, const QModelIndex& parent) const {
    qDebug() << "calling index";
    if (!hasIndex(row, column, parent)) {
        return QModelIndex();
    }

    RuneNode* parentItem;

    if (!parent.isValid()) {
        parentItem = static_cast<RuneNode*>(root.get());
    } else {
        parentItem = static_cast<RuneNode*>(parent.internalPointer());
    }
	
    AbstractRuneNode* childItem = parentItem->child(row);
    if (childItem) {
        return createIndex(row, column, childItem);
    }
    return QModelIndex();
}

QModelIndex RuneTreeModel::parent(const QModelIndex& index) const {
    qDebug() << "calling parent";
    if (!index.isValid()) {
        return QModelIndex();
    }

    AbstractRuneNode* childItem = static_cast<AbstractRuneNode*>(index.internalPointer());
    AbstractRuneNode* parentItem = childItem->getParent();

    if (parentItem == root.get()) {
        return QModelIndex();
    }

    return createIndex(RuneNodeOperations::row(*parentItem), 0, parentItem);
}

int RuneTreeModel::rowCount(const QModelIndex& parent) const {
    qDebug() << "calling row count";
    RuneNode* parentItem;
    if (parent.column() > 0) {
        return 0;
    }

    if (!parent.isValid()) {
        parentItem = static_cast<RuneNode*>(root.get());
    } else {
        parentItem = static_cast<RuneNode*>(parent.internalPointer());
    }

    return parentItem->numberOfChildren();
}

void RuneTreeModel::initializeRuneTree() {
    qDebug() << "initializing";
    root = std::make_unique<RootNode>(ROOT_NAME, nullptr);
    RuneNode* zentralrunen = new RuneNode("Zentralrunen", root.get());
    static_cast<RuneNode*>(root.get())->addChild(zentralrunen);

    RuneLeaf* schaffen = new RuneLeaf("schaffen", 5, zentralrunen);
    zentralrunen->addChild(schaffen);
}

bool RuneTreeModel::setData(const QModelIndex& index, const QVariant& value, int role) {
    if (role != Qt::EditRole)
        return false;

    RuneLeaf* item = getRuneleafPointer(index);
	if (!item) {
        return false;
	}

    item->setAmount(value.toUInt());
    emit dataChanged(index, index, { Qt::DisplayRole, Qt::EditRole });

    return true;
}

RuneLeaf* RuneTreeModel::getRuneleafPointer(QModelIndex index) const {
    if (!index.isValid()) {
        return nullptr;
    }
    return static_cast<AbstractRuneNode*>(index.internalPointer())->isLeaf() ? static_cast<RuneLeaf*>(index.internalPointer()) : nullptr;
   // return dynamic_cast<RuneLeaf*>(index.internalPointer());
}
