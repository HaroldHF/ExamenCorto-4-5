
#pragma once
#include <vector>
#include "Edge.hpp"
class Reporter {
public:
    static void saveFullReport(const std::vector<Edge>& edges,
                               const std::vector<Edge>& mst,
                               int totalCost,
                               const std::string& filename);
};
