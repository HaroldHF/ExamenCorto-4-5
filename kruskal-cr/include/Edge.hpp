
#pragma once
struct Edge {
    int u;
    int v;
    int cost;
    Edge(int u_, int v_, int cost_);
};
bool edgeCostLess(const Edge& a, const Edge& b);
