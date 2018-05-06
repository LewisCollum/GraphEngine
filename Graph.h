#pragma once
#include "GraphComponent.h"
#include <vector>
#include <initializer_list>

// TODO check to make sure move semantics are correct
// TODO finish making this class a proper wrapper for an STL container

// Component Design Pattern
class Graph : public GraphComponent
{
public: // Typedefs
	typedef std::forward_list<GraphComponent*> link_container;
	typedef const GraphComponent& parent_const_reference;
	typedef GraphComponent& parent_reference;
	typedef GraphComponent* parent_pointer; // TODO unique pointers
	typedef GraphComponent parent_value_type;
	typedef std::vector<parent_pointer> component_container;
	typedef component_container::const_iterator component_const_iterator;
	typedef size_t size_type;

public: // Constructors
	Graph(Graph&& g) : components(g.components) { g.components = nullptr; }
	Graph() : components(new component_container()) {}
	Graph(std::initializer_list<parent_pointer> args) : components(new component_container(args)) {}
	~Graph() { delete components; }

public: // Public Functions
	void link(parent_reference, bool bidi = true) override;
	void unlink(parent_reference, bool bidi = true) override;
	void add(parent_pointer) override;
	component_container const& getComponents() const { return *components; } // TODO remove getter during refactoring
	Graph& operator=(Graph&&);
	const parent_reference operator[](size_type i) const override { return *(*components)[i]; }
	parent_reference operator[](size_type i) override { return *(*components)[i];  }
	size_type size() const override { return components->size(); }

private: // Private Names
	component_container* components;
};