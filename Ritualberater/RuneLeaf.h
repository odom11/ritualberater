#pragma once
#include "AbstractRuneNode.h"

class RuneLeaf : public AbstractRuneNode {
public:
	RuneLeaf(const std::string& name, const int cost, AbstractRuneNode * parent);
	void setAmount(unsigned int amount);
	unsigned int getAmount() const;
	unsigned int columnCount() override;
	QVariant data(unsigned column) const override;
	bool isLeaf() const override { return true; };
private:
	const unsigned int cost;
	unsigned int amount;
};

