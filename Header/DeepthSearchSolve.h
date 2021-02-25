#pragma once
#include <iostream>
#include "ConnectedGraph.h"
#include "TaskGenerator.h"

class DeepthSearchSolve : public ConnectedGraph
{
private:
    void setMatrix(std::vector<int>);
    void setGraphAndReverseGraph(int n);
    void resizeMatrix();
    void setGraphFromTaskGenerator(std::vector<std::pair<int, int>> graph);
    std::vector<int> deepthFirstSearch1(int v);
    std::vector<int> deepthFirstSearch2(int v);
    
public:
    DeepthSearchSolve(TaskGenerator* task);
    DeepthSearchSolve(int n, std::vector<int> matrix);
    ~DeepthSearchSolve() = default;
    int solve() override;
};
