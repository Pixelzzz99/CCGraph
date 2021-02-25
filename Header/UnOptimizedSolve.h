#pragma once
#include <iostream>
#include "ConnectedGraph.h"
#include "TaskGenerator.h"
class UnOptimizedSolve : public ConnectedGraph
{
private:
    void setMatrix(std::vector<int>);
    void setGraphAndReverseGraph(int n);
    void resizeMatrix();
    void setGraphFromTaskGenerator(std::vector<std::pair<int, int>> graph);

    void dfs1(int v);
    void dfs2(int v);

public:
    UnOptimizedSolve(TaskGenerator* task);
    UnOptimizedSolve(int n, std::vector<int> matrix);
    ~UnOptimizedSolve() = default;
    int solve() override;
};
