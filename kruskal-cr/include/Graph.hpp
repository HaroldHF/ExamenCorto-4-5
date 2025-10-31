
#pragma once
#include <vector>
#include "Edge.hpp"
#include "City.hpp"
class Graph {
    std::vector<Edge> edges;
public:
    void buildCompleteWithCosts(int cost);
    void printAllEdges() const;
    std::vector<Edge> kruskalMST(int vertexCount, int& outTotalCost) const;
    const std::vector<Edge>& getEdges() const;
};
