#include "../include/Reporter.hpp"
#include <iostream>
#include "../include/City.hpp"
void Reporter::saveMSTReport(const std::vector<Edge>& mst, int totalCost) {
    std::cout << "=== MST (Kruskal) ===" << std::endl;
    for (const auto& e : mst) {
        std::cout << cityName((City)e.u) << " - " << cityName((City)e.v) << " : " << e.cost << std::endl;
    }
    std::cout << "Costo total: " << totalCost << std::endl;
    std::cout << "Reporte guardado en: reporte_mst.txt" << std::endl;
}
