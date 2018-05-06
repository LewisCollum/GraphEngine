#include "GraphComponent.h"
#include <algorithm>

bool GraphComponent::isLinked(const_reference c) const {
	return std::find(links.begin(), links.end(), &c) != links.end();
}

bool GraphComponent::noLinks() const {
	return links.empty();
}