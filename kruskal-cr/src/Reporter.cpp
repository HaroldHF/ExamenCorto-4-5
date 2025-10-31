#include <vector>
#include <string>
#include <ostream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <functional>
#include "../include/Reporter.hpp"
#include "../include/Graph.hpp"
#include "../include/City.hpp"
#include "../include/Edge.hpp"

// Dibuja cualquier grafo como árbol ASCII (no necesariamente un árbol real)

// ...existing code...

// Dibuja cualquier grafo como árbol ASCII (no necesariamente un árbol real)
static void printAsciiGraph(const std::vector<Edge>& edges, std::ostream& out) {
    std::vector<std::string> names = {
        "San Jose", "Alajuela", "Cartago", "Heredia", "Limon", "Puntarenas"
    };
    std::vector<std::vector<std::pair<int, int>>> adj(6);
    for (const auto& e : edges) {
        adj[e.u].push_back({e.v, e.cost});
        adj[e.v].push_back({e.u, e.cost});
    }
    std::vector<bool> visited(6, false);
    std::function<void(int, int, std::string, bool)> dfs = [&](int u, int parent, std::string prefix, bool isLast) {
        out << prefix;
        if (parent == -1) {
            out << "[ " << names[u] << " ]\n";
        } else {
            out << (isLast ? "└── " : "├── ");
            out << "[ " << names[u] << " ]\n";
            out << prefix << (isLast ? "    " : "│   ");
            out << "Costo: " << adj[u][std::find_if(adj[u].begin(), adj[u].end(), [&](auto& p){return p.first==parent;}) - adj[u].begin()].second << "\n";
        }
        visited[u] = true;
        int children = 0;
        for (auto& v : adj[u]) if (!visited[v.first]) children++;
        int cnt = 0;
        for (auto& v : adj[u]) {
            if (!visited[v.first]) {
                dfs(v.first, u, prefix + (isLast ? "    " : "│   "), ++cnt == children);
            }
        }
    };
    int root = 0;
    dfs(root, -1, "", true);
}


#include <vector>
#include <string>
#include <ostream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "../include/Reporter.hpp"
#include "../include/Graph.hpp"
#include "../include/City.hpp"
#include "../include/Edge.hpp"



static void printAdjacencyList(const std::vector<Edge>& edges, std::ostream& out);

// Solo dejar la definición de printKruskalSteps al final

void Reporter::printKruskalSteps(const std::vector<KruskalStep>& steps, std::ostream& out) {
    int paso = 1;
    for (const auto& s : steps) {
        out << "Paso " << paso++ << ": Considerando arista "
            << cityName((City)s.edge.u) << " - " << cityName((City)s.edge.v)
            << " (" << s.edge.cost << ")";
        if (s.added) {
            out << " -> Se agrega al MST\n";
        } else {
            out << " -> Se descarta (formaría ciclo)\n";
        }
        out << "MST parcial como lista de adyacencia:\n";
        printAdjacencyList(s.mstPartial, out);
        out << "-----------------------------\n";
    }
}


// Dibuja el MST como árbol ASCII con nombres y costos, formato similar al ejemplo
static void printAsciiTree(const std::vector<Edge>& mst, std::ostream& out) {
    std::vector<std::string> names = {
        "San Jose", "Alajuela", "Cartago", "Heredia", "Limon", "Puntarenas"
    };
    // Construir adyacencias
    std::vector<std::vector<std::pair<int, int>>> adj(6);
    for (const auto& e : mst) {
        adj[e.u].push_back({e.v, e.cost});
        adj[e.v].push_back({e.u, e.cost});
    }
    std::vector<bool> visited(6, false);
    // Función recursiva para imprimir el árbol
    std::function<void(int, int, std::string, bool)> dfs = [&](int u, int parent, std::string prefix, bool isLast) {
        out << prefix;
        if (parent == -1) {
            out << "[ " << names[u] << " ]\n";
        } else {
            out << (isLast ? "└── " : "├── ");
            out << "[ " << names[u] << " ]\n";
            out << prefix << (isLast ? "    " : "│   ");
            out << "Costo: " << adj[u][std::find_if(adj[u].begin(), adj[u].end(), [&](auto& p){return p.first==parent;}) - adj[u].begin()].second << "\n";
        }
        visited[u] = true;
        int children = 0;
        for (auto& v : adj[u]) if (!visited[v.first]) children++;
        int cnt = 0;
        for (auto& v : adj[u]) {
            if (!visited[v.first]) {
                dfs(v.first, u, prefix + (isLast ? "    " : "│   "), ++cnt == children);
            }
        }
    };
    // Buscar raíz (nodo con mayor grado o San Jose por defecto)
    int root = 0;
    dfs(root, -1, "", true);
}

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

static void printAdjacencyList(const std::vector<Edge>& edges, std::ostream& out) {
    std::vector<std::string> names = {
        "San Jose", "Alajuela", "Cartago", "Heredia", "Limon", "Puntarenas"
    };
    std::vector<std::vector<std::pair<int, int>>> adj(6);
    for (const auto& e : edges) {
        adj[e.u].push_back({e.v, e.cost});
        adj[e.v].push_back({e.u, e.cost});
    }
    for (int i = 0; i < 6; ++i) {
        out << names[i] << " -> ";
        for (size_t j = 0; j < adj[i].size(); ++j) {
            out << names[adj[i][j].first] << "(" << adj[i][j].second << ")";
            if (j + 1 < adj[i].size()) out << ", ";
        }
        out << "\n";
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
    // Grafo estructurado visual
    fout << "=== GRAFO COMO LISTA DE ADYACENCIA ===\n";
    printAdjacencyList(edges, fout);
    fout << "\n=== GRAFO COMO ÁRBOL ASCII ===\n";
    printAsciiGraph(edges, fout);
    fout << "\n=== MST (KRUSKAL) COMO LISTA DE ADYACENCIA ===\n";
    printAdjacencyList(mst, fout);
    fout << "\n=== ÁRBOL MST EN ASCII ===\n";
    printAsciiTree(mst, fout);
    fout << "\n=== MATRIZ DE ADYACENCIA DEL GRAFO ===\n";
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
