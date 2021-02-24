#pragma once
#include <iostream>
#include "ConnectedGraph.h"
#include "TaskGenerator.h"
class UnOptimizedSolve : public ConnectedGraph
{
private:

    std::vector<std::vector<int>> RosterOne;
    std::vector<std::vector<int>> RosterTwo;
    void setMatrix(std::vector<int>);
    void setGraphAndReverseGraph(int n);
    void resizeMatrix();
    void resizeRosters();
    void dfs1(int v);
    void dfs2(int v);

public:
    UnOptimizedSolve(TaskGenerator* task);
    UnOptimizedSolve(int n, std::vector<int> matrix);
    ~UnOptimizedSolve() = default;
    void solve() override;
};
