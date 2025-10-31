#include "../include/Graph.hpp"
#include "../include/UnionFind.hpp"
#include "../include/Edge.hpp"
#include <iostream>
#include <iomanip>
#include <vector>

void Graph::printAdjacencyMatrixMST(const std::vector<Edge>& mst) {
    int matrix[CITY_COUNT][CITY_COUNT] = {};
    for (const auto& e : mst) {
        matrix[e.u][e.v] = e.cost;
        matrix[e.v][e.u] = e.cost;
    }
    std::cout << std::setw(12) << "";
    for (int j = 0; j < CITY_COUNT; ++j)
        std::cout << std::setw(12) << cityName((City)j);
    std::cout << std::endl;
    for (int i = 0; i < CITY_COUNT; ++i) {
        std::cout << std::setw(12) << cityName((City)i);
        for (int j = 0; j < CITY_COUNT; ++j) {
            if (i == j) std::cout << std::setw(12) << "—";
            else if (matrix[i][j]) std::cout << std::setw(12) << matrix[i][j];
            else std::cout << std::setw(12) << "";
        }
        std::cout << std::endl;
    }
}
// ...existing code...
#include "../include/Graph.hpp"
#include "../include/UnionFind.hpp"
#include "../include/Edge.hpp"
#include <iostream>
#include <vector>
 #include <fstream>
 #include <iomanip>
void Graph::buildCompleteWithCosts(int cost) {
    for (int u = 0; u < CITY_COUNT; ++u) {
        for (int v = u + 1; v < CITY_COUNT; ++v) {
            edges.push_back(Edge(u, v, cost));
        }
    }
}

void Graph::buildFromFile(const std::string& filename) {
    edges.clear();
    std::ifstream fin(filename);
    if (!fin) {
        std::cerr << "No se pudo abrir " << filename << std::endl;
        return;
    }
    int u, v, cost;
    while (fin >> u >> v >> cost) {
        edges.push_back(Edge(u, v, cost));
    }
}

void Graph::printAdjacencyMatrix() const {
    int matrix[CITY_COUNT][CITY_COUNT] = {};
    for (const auto& e : edges) {
        matrix[e.u][e.v] = e.cost;
        matrix[e.v][e.u] = e.cost;
    }
    std::cout << std::setw(12) << "";
    for (int j = 0; j < CITY_COUNT; ++j)
        std::cout << std::setw(12) << cityName((City)j);
    std::cout << std::endl;
    for (int i = 0; i < CITY_COUNT; ++i) {
        std::cout << std::setw(12) << cityName((City)i);
        for (int j = 0; j < CITY_COUNT; ++j) {
            if (i == j) std::cout << std::setw(12) << "—";
            else if (matrix[i][j]) std::cout << std::setw(12) << matrix[i][j];
            else std::cout << std::setw(12) << "";
        }
        std::cout << std::endl;
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
