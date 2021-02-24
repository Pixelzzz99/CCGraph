#pragma once
#include <vector>

class ConnectedGraph
{
private:
    int _countOfVertex_N;

protected:
    std::vector<bool> used;
    std::vector<int> order;
    std::vector<int> component;
    std::vector<std::vector<int>> _matrix;
    std::vector<std::vector<int>> _graph;
    std::vector<std::vector<int>> _graph_reverse;

public:
    int getCountOfVertex_N();
    void setCountOfVertex_N(int new_n);
    ~ConnectedGraph() = default;
    virtual void solve() = 0;
};
