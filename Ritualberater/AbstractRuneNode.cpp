#include "AbstractRuneNode.h"

AbstractRuneNode::AbstractRuneNode(const std::string& name, AbstractRuneNode* parent) : name(name), parent(parent) {}

AbstractRuneNode::~AbstractRuneNode() {}

AbstractRuneNode* AbstractRuneNode::getParent() {
	return parent;
}

QVariant AbstractRuneNode::data(unsigned column) const {
	if (column == 0) {
		return QVariant(QString::fromStdString(name));
	}
	return QVariant();
}




