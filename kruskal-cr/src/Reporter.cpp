

#include "../include/Reporter.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include "../include/City.hpp"

static void printMatrixToStream(std::ostream& out, const std::vector<Edge>& edges) {
    int matrix[CITY_COUNT][CITY_COUNT] = {};
    for (const auto& e : edges) {
        matrix[e.u][e.v] = e.cost;
        matrix[e.v][e.u] = e.cost;
    }
    out << std::setw(12) << "";
    for (int j = 0; j < CITY_COUNT; ++j)
        out << std::setw(12) << cityName((City)j);
    out << std::endl;
    for (int i = 0; i < CITY_COUNT; ++i) {
        out << std::setw(12) << cityName((City)i);
        for (int j = 0; j < CITY_COUNT; ++j) {
            if (i == j) out << std::setw(12) << "—";
            else if (matrix[i][j]) out << std::setw(12) << matrix[i][j];
            else out << std::setw(12) << "";
        }
        out << std::endl;
    }
}

void Reporter::saveFullReport(const std::vector<Edge>& edges,
                              const std::vector<Edge>& mst,
                              int totalCost,
                              const std::string& filename) {
    std::ofstream fout(filename);
    if (!fout) {
        std::cerr << "No se pudo guardar el archivo: " << filename << std::endl;
        return;
    }
    fout << "=== MATRIZ DE ADYACENCIA DEL GRAFO ===\n";
    printMatrixToStream(fout, edges);
    fout << "\n=== RECORRIDO DE TODAS LAS CONEXIONES ===\n";
    for (const auto& e : edges) {
        fout << cityName((City)e.u) << " - " << cityName((City)e.v) << " : " << e.cost << std::endl;
    }
    fout << "\n=== MATRIZ DE ADYACENCIA DEL MST (Kruskal) ===\n";
    printMatrixToStream(fout, mst);
    fout << "\n=== MST (Kruskal) ===\n";
    for (const auto& e : mst) {
        fout << cityName((City)e.u) << " - " << cityName((City)e.v) << " : " << e.cost << std::endl;
    }
    fout << "Costo total: " << totalCost << std::endl;
    fout << "Reporte guardado en: " << filename << std::endl;
    fout.close();
}
