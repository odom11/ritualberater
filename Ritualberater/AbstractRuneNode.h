#pragma once

#include <string>
#include <QVariant>

class AbstractRuneNode;

namespace RuneNodeOperations
{
	unsigned int row(const AbstractRuneNode& node);
}

class AbstractRuneNode {
	friend unsigned int RuneNodeOperations::row(const AbstractRuneNode& node);
public:
	explicit AbstractRuneNode(const std::string& name, AbstractRuneNode * parent);
	virtual ~AbstractRuneNode() = 0;
	AbstractRuneNode * getParent();
	virtual unsigned int columnCount() = 0;
	virtual QVariant data(unsigned int column) const;
	virtual bool isLeaf() const { return false; };

private:
	const std::string name;
	AbstractRuneNode *const parent;
};

