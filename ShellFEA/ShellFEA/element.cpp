#include "element.h"

Element::Element()
{
	nodes = nullptr;
	node_ids = nullptr;
}

Element::Element(std::vector<double>* n, std::vector<int>* n_id) : nodes(n), node_ids(n_id) {}

