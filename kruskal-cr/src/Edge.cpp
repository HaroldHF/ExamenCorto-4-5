#include "../include/Edge.hpp"
Edge::Edge(int u_, int v_, int cost_) : u(u_), v(v_), cost(cost_) {}
bool edgeCostLess(const Edge& a, const Edge& b) {
    return a.cost < b.cost;
}
