#include "RuneLeaf.h"

RuneLeaf::RuneLeaf(const std::string& name, const int cost, AbstractRuneNode * parent) : AbstractRuneNode(name, parent), cost(cost), amount(0) {}

unsigned RuneLeaf::getAmount() const
{
	return amount;
}

void RuneLeaf::setAmount(unsigned amount)
{
	this->amount = amount;
}

unsigned int RuneLeaf::columnCount()
{
	return 3;
}

QVariant RuneLeaf::data(unsigned int column) const
{
	enum COLUMN { COST = 1, AMOUNT = 2 };
	switch (column)
	{
	case COST:
		return QVariant(cost);
	case AMOUNT:
		return QVariant(amount);
	default:
		return AbstractRuneNode::data(column);
	}
}

