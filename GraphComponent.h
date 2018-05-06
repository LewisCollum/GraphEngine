#pragma once
#include <forward_list>

// TODO turn class into propper STL container wrapper

class GraphComponent
{
public:	// Typedefs
	typedef std::forward_list<GraphComponent*> link_container;
	typedef const GraphComponent& const_reference;
	typedef GraphComponent& reference;
	typedef GraphComponent* pointer;
	typedef size_t size_type;

public:	// Public Functions
	virtual void link(reference, bool bidi = true) = 0;
	virtual void unlink(reference, bool bidi = true) = 0;
	bool isLinked(const_reference) const;
	bool noLinks() const;
	link_container const& getLinks() const { return links; } // TODO remove getter
	virtual size_type size() const = 0;
	virtual const GraphComponent& operator[](size_type i) const = 0; // TODO I would prefer to have to only defined in Graph but i run into issues in match_GS function
	virtual GraphComponent& operator[](size_type i) = 0;
	virtual void add(pointer) = 0; // TODO I would prefer to have to only defined in Graph but i run into issues in match_GS function
protected: // Protected Names
	link_container links;
};

