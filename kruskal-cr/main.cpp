
#include "include/City.hpp"
#include "include/Edge.hpp"
#include "include/UnionFind.hpp"
#include "include/Graph.hpp"
#include "include/Reporter.hpp"
#include <iostream>
int main() {
    Graph g;
    g.buildFromFile("kruskal-cr/grafo.txt");
    std::cout << "\n=== MATRIZ DE ADYACENCIA DEL GRAFO ===\n";
    g.printAdjacencyMatrix();
    std::cout << "\n=== RECORRIDO DE TODAS LAS CONEXIONES ===\n";
    g.printAllEdges();
    std::cout << "\n=== MATRIZ DE ADYACENCIA DEL MST (Kruskal) ===\n";
    int totalCost = 0;
    auto steps = g.kruskalSteps(CITY_COUNT, totalCost);
    std::vector<Edge> mst;
    if (!steps.empty()) {
        mst = steps.back().mstPartial;
    }
    Graph::printAdjacencyMatrixMST(mst);
    std::cout << "\n=== PASOS DEL ALGORITMO KRUSKAL ===\n";
    Reporter::printKruskalSteps(steps, std::cout);
    Reporter::saveFullReport(g.getEdges(), mst, totalCost, "kruskal-cr/reporte_mst.txt");
    return 0;
}
