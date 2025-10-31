
#include "include/City.hpp"
#include "include/Edge.hpp"
#include "include/UnionFind.hpp"
#include "include/Graph.hpp"
#include "include/Reporter.hpp"
#include <iostream>
int main() {
    const int COST = 100; // TODO: cambiar por aleatorio si se permite
    Graph g;
    g.buildCompleteWithCosts(COST);
    std::cout << "=== TODAS LAS CONEXIONES (costo fijo) ===" << std::endl;
    g.printAllEdges();
    int totalCost = 0;
    auto mst = g.kruskalMST(CITY_COUNT, totalCost);
    Reporter::saveMSTReport(mst, totalCost);
    return 0;
}
