
#pragma once
#include <vector>
class UnionFind {
    std::vector<int> parent;
    std::vector<int> rank;
public:
    UnionFind(int n);
    int find(int x);
    bool unite(int a, int b);
    bool same(int a, int b) const;
};
