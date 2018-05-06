#include "Vertex.h"

void Vertex::link(parent_reference c, bool bidi) {
	links.emplace_front(&c);
	if (bidi) c.link(*this, false);
}

void Vertex::unlink(parent_reference c, bool bidi) {
	links.remove(&c);
	if (bidi) c.unlink(*this, false);
}