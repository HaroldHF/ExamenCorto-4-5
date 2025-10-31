
#pragma once
#include <vector>
#include "Edge.hpp"
class Reporter {
public:
    static void saveMSTReport(const std::vector<Edge>& mst, int totalCost);
};
