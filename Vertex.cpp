#include "Vertex.h"

void Vertex::addEdge(Vertex* successor, const double& probability)
{
    edges.push_back(Edge(successor, probability));
}