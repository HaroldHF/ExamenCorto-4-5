
#pragma once
#include <vector>
#include "Edge.hpp"
#include "City.hpp"

struct KruskalStep {
    Edge edge;
    bool added; // true si se agrega al MST, false si se descarta
    std::vector<Edge> mstPartial;
};

class Graph {
    std::vector<Edge> edges;
public:
    void buildCompleteWithCosts(int cost);
    void buildFromFile(const std::string& filename);
    void printAdjacencyMatrix() const;
    static void printAdjacencyMatrixMST(const std::vector<Edge>& mst);
    void printAllEdges() const;
    std::vector<Edge> kruskalMST(int vertexCount, int& outTotalCost) const;
    std::vector<KruskalStep> kruskalSteps(int vertexCount, int& outTotalCost) const;
    const std::vector<Edge>& getEdges() const;
};
