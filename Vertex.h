#pragma once
#include "GraphComponent.h"

class Vertex : public GraphComponent
{
public: // typenames
	typedef std::forward_list<GraphComponent*> link_container;
	typedef const GraphComponent& parent_const_reference;
	typedef GraphComponent& parent_reference;
	typedef GraphComponent* parent_pointer;
	typedef size_t size_type;

public: // Constructors
	Vertex() {}

public: // Public Functions
	void link(parent_reference, bool bidi = true) override;
	void unlink(parent_reference, bool bidi = true) override;
	size_type size() const override { return 1; }
	const GraphComponent& operator[](size_type i) const override { return *this; }
	parent_reference operator[](size_type i) override { return *this; }
	void add(parent_pointer) override {} // TODO figure out how to not do it like this

};

