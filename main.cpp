#include <iostream>
#include <iterator>
#include <algorithm>
#include "Graph.h"
#include "GraphComponent.h"
#include "Vertex.h"

#include <array>
#include <time.h>
#include <stdlib.h>

// ALGORITHMS
Graph match_GS(const Graph&);

// DEBUG FUNCTIONS
void printGraph(const Graph&);
void printSize(const GraphComponent&);
void histogramGraphSize(const Graph&);

class Cell {
public:
	int cellType;
	Cell() {};
	Cell(int cellType) : cellType(cellType) {};
};

template <int WIDTH, int HEIGHT>
class Map {
	std::array < std::array<Cell*, WIDTH>, HEIGHT> map;
public:
	void setup() {
		for (int i = 0; i < WIDTH; ++i) std::cout << "+---";
		std::cout << '+' << std::endl;

		for (int y = 0; y < HEIGHT; ++y) {
			std::cout << '|';
			for (int x = 0; x < WIDTH; ++x) {
				map[y][x] = new Cell(randomCellType());
			
				if (withinBounds(y - 1, x)) {
					if (map[y][x]->cellType == map[y - 1][x]->cellType)
						std::cout << "   |" ;
					else std::cout << ' ' << map[y][x]->cellType << " |";
				}
				else if (withinBounds(y, x - 1)) {
					if (map[y][x]->cellType == map[y][x - 1]->cellType)
						std::cout << "   |";
					else std::cout << ' ' << map[y][x]->cellType << " |";
				}
				else std::cout << "   |";
				//else std::cout << ' ' << map[y][x]->cellType << " |";
				//std::cout << '|';
			}
			std::cout << std::endl;
			for (int i = 0; i < WIDTH; ++i) std::cout << "+---";
			std::cout << '+' << std::endl;
		}
	}

	int randomCellType() {
		return rand() % 3 + 0;
	}

	bool withinBounds(int y, int x) {
		return x > 0 && x < WIDTH && y > 0 && y < HEIGHT;
	}


};

int main() {
	//std::srand(time(NULL));
	std::srand(1);
	Map<10, 10> m;
	m.setup();

	Vertex a;
	Graph t = { new Vertex(), new Vertex(), new Vertex() };
	Graph foo = { &a, &t };
	for (int i = 0; i < 5; ++i) foo.add(new Vertex());

	std::cout << "foo size: " << std::endl;
	printSize(foo);
	std::cout << std::endl;

	std::cout << "foo[0] size: " << std::endl;
	printSize(foo[0]);
	std::cout << "foo[1] size: " << std::endl;
	printSize(foo[1]);
	std::cout << std::endl;

	std::cout << "foo histogram: " << std::endl;
	histogramGraphSize(foo);

	//Gale-Shapley Algorithm
	Graph pGraph{ new Graph(), new Graph() };
	for (int i = 0; i < 10; ++i) {
		pGraph[0].add(new Vertex());
		pGraph[1].add(new Vertex());
	}
	pGraph[0][0].link(pGraph[1][0]);

	Graph matches = match_GS(pGraph);

	std::cout << std::endl;
	histogramGraphSize(matches);

	
	
	return 0;
}


// DEBUG FUNCTIONS
void printGraph(const Graph& g) {
	Graph::component_const_iterator i = g.getComponents().begin();
	for (; i != g.getComponents().end(); ++i) std::cout << *i << std::endl;
}

void printSize(const GraphComponent& c) {
	std::cout << &c << " : " << c.size() << " (components)" << std::endl;
}

void histogramGraphSize(const Graph& g) {
	for (int i = 0; i < g.size() ; ++i) {
		std::cout << &g[i] << " : ";
		for (int j = 0; j < g[i].size(); ++j) {	std::cout << "#"; }
		std::cout << std::endl;
	}
}

//ALGORITHMS
Graph match_GS(const Graph& p) {
	/* TODO: Transpareny (same interface) or safety (type-safe)
		I want to use Graph& = ret[0] 
		TODO should I copy preference list and manipulate preference graph?
	*/
	Graph ret = { new Graph(), new Graph() };
	GraphComponent& proposers = ret[0];
	GraphComponent& acceptors = ret[1];

	if (p.size() == 2) {
		const GraphComponent& p_proposers = p[0];
		const GraphComponent& p_acceptors = p[1];

		for (int i = 0; i < p_proposers.size(); ++i) {
			proposers.add(new Vertex());
			acceptors.add(new Vertex());
		}
		
		for (int i = 0; i < proposers.size(); ++i) {
			if (proposers[i].noLinks()) {
				//Graph::component_const_iterator suitor = acceptors;
				//while (p_proposers[i].getLinks().begin() != &p_acceptors[count]) count++;
				// TODO figure out how to mirror objects from one container to another
				//GraphComponent& suitor = acceptors[count];
				if (p_proposers[i].noLinks()) {
					//proposers[i].link(suitor);
				}
			}
		}
	}
	else {
		std::cout << "You must provide a bipartite graph (i.e. Graph must contain two GraphComponents)." << std::endl;
	}
	
	return ret;
}

//Graph randomizeGraph
