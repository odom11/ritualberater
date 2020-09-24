#pragma once

#include <memory>
#include <vector>
#include "AbstractRuneNode.h"

namespace RuneNodeOperations
{
	unsigned int row(const AbstractRuneNode& child);
}

class RuneNode : public AbstractRuneNode
{
	friend unsigned int RuneNodeOperations::row(const AbstractRuneNode& child);
public:
	RuneNode(const std::string& name, AbstractRuneNode * parent);
	void addChild(AbstractRuneNode* child);
	unsigned int numberOfChildren() const;
	AbstractRuneNode* child(unsigned int row);
	unsigned int columnCount() override;
private:
	std::vector<std::unique_ptr<AbstractRuneNode>> children;
};

