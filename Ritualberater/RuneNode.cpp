#include "RuneNode.h"

RuneNode::RuneNode(const std::string& name, AbstractRuneNode * parent) : AbstractRuneNode(name, parent) {

}


void RuneNode::addChild(AbstractRuneNode* child) {
	children.push_back(std::unique_ptr<AbstractRuneNode>(child));
}

unsigned int RuneNode::numberOfChildren() const {
	return children.size();
}

AbstractRuneNode* RuneNode::child(unsigned row) {
	if (row >= children.size()) {
		return nullptr;
	}
	return children[row].get();
}

unsigned RuneNode::columnCount()
{
	return 3;
}

