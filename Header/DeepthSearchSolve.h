#pragma once
#include <iostream>
#include "ConnectedGraph.h"
#include "TaskGenerator.h"

class DeepthSearchSolve : public ConnectedGraph
{
private:
    std::vector<bool> used;
    std::vector<int> order;
    std::vector<int> component;
    void setMatrix(std::vector<int>);
    void setGraphAndReverseGraph(int n);
    void resizeMatrix();

    std::vector<int> deepthFirstSearch1(int v);
    std::vector<int> deepthFirstSearch2(int v);
    
public:
    DeepthSearchSolve(TaskGenerator task);
    DeepthSearchSolve(int n, std::vector<int> matrix);
    ~DeepthSearchSolve() = default;
    void solve() override;
};
