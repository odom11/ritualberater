#include <stdexcept>

#include "AbstractRuneNode.h"
#include "RuneNode.h"

namespace RuneNodeOperations {
	unsigned int row(const AbstractRuneNode& child) {
		if (!child.parent) {
			return 0;
		}
		RuneNode const* parent = static_cast<RuneNode const*>(child.parent);
		auto it = std::find_if(parent->children.begin(), parent->children.end(), [&](const auto& ptr) {return ptr.get() == &child; });;
		if (it == parent->children.end()) {
			throw std::runtime_error("child not found in parent's children. implementation error");
		}
		return std::distance(parent->children.begin(), it);
	}
}
