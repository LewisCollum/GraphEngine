#include "Graph.h"

void Graph::link(parent_reference, bool bidi) {
	// TODO implement strategy for linking graphs to other components (must work for amorphous graphs i.e. non-orthogonal)
	// Will most likely pass this function to a decorator subclass that has coordinate functionality
}

void Graph::unlink(parent_reference, bool bidi) {
	// TODO implement a search and remove algorithm cycling through each component in graph
}

void Graph::add(parent_pointer c) {
	components->push_back(c);
}

Graph& Graph::operator=(Graph&& g)
{
	delete components;
	components = g.components;
	g.components = nullptr;
	return *this;
}
