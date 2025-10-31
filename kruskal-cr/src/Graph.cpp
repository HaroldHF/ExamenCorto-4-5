#include "../include/Graph.hpp"
#include "../include/UnionFind.hpp"
#include <iostream>
void Graph::buildCompleteWithCosts(int cost) {
    for (int u = 0; u < CITY_COUNT; ++u) {
        for (int v = u + 1; v < CITY_COUNT; ++v) {
            edges.push_back(Edge(u, v, cost));
        }
    }
}
void Graph::printAllEdges() const {
    for (const auto& e : edges) {
        std::cout << cityName((City)e.u) << " - " << cityName((City)e.v) << " : " << e.cost << std::endl;
    }
}
std::vector<Edge> Graph::kruskalMST(int vertexCount, int& outTotalCost) const {
    std::vector<Edge> mst;
    outTotalCost = 0;
    std::vector<Edge> sortedEdges = edges;
    for (size_t i = 0; i < sortedEdges.size(); ++i) {
        for (size_t j = i + 1; j < sortedEdges.size(); ++j) {
            if (edgeCostLess(sortedEdges[j], sortedEdges[i])) std::swap(sortedEdges[i], sortedEdges[j]);
        }
    }
    UnionFind uf(vertexCount);
    for (const auto& e : sortedEdges) {
        if (uf.unite(e.u, e.v)) {
            mst.push_back(e);
            outTotalCost += e.cost;
        }
    }
    return mst;
}
const std::vector<Edge>& Graph::getEdges() const { return edges; }
