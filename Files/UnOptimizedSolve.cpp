#include "UnOptimizedSolve.h"

UnOptimizedSolve::UnOptimizedSolve(TaskGenerator *task)
{
    setCountOfVertex_N(task->get_N());
    setGraphFromTaskGenerator(task->get_Graph());
}

void UnOptimizedSolve::setGraphFromTaskGenerator(std::vector<std::pair<int, int>> graph)
{
    used.resize(getCountOfVertex_N() + 1);
    _graph.resize(getCountOfVertex_N() + 1);
    _graph_reverse.resize(getCountOfVertex_N() + 1);
    for (int i = 0; i < getCountOfVertex_N() + 1; i++)
    {
        _graph[i].resize(getCountOfVertex_N() + 1);
        _graph_reverse[i].resize(getCountOfVertex_N() + 1);
    }
    for (auto element : graph)
    {
        int i = element.first;
        int j = element.second;
        _graph[i][j] = _graph_reverse[j][i] = 1;
    }
}

UnOptimizedSolve::UnOptimizedSolve(int n, std::vector<int> matrix)
{
    setCountOfVertex_N(n);
    resizeMatrix();
    setMatrix(matrix);
    setGraphAndReverseGraph(n);
}


void UnOptimizedSolve::resizeMatrix()
{
    _matrix.resize(getCountOfVertex_N() + 1);
}

void UnOptimizedSolve::setMatrix(std::vector<int> matrix)
{
    for (int i = 1; i <= getCountOfVertex_N(); i++)
    {
        _matrix[i].push_back(matrix[i]);
    }
}

void UnOptimizedSolve::setGraphAndReverseGraph(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (_matrix[i][j])
            {
                _graph[i].push_back(j);
                _graph_reverse[j].push_back(i);
            }
        }
    }
}

void UnOptimizedSolve::dfs1(int v)
{
    used[v] = true;
    for (int i = 1; i <= getCountOfVertex_N(); i++)
    {
        if (!_graph[v][i] || used[i])
            continue;
        dfs1(i);
    }
    order.push_back(v);
}

void UnOptimizedSolve::dfs2(int v)
{
    used[v] = true;
    component.push_back(v);
    for (int i = 1; i <= getCountOfVertex_N(); i++)
    {
        if (!_graph_reverse[v][i] || used[i])
            continue;
        dfs2(i);
    }
}

int UnOptimizedSolve::solve()
{
    int n = getCountOfVertex_N();
    for (int i = 1; i <= n; i++)
        if (!used[i])
            dfs1(i);
    for (int i = 1; i <= n; i++)
        used[i] = false;
    int countOfComponents = 0;
    for (int i = 1; i <= n; i++)
    {
        int v = order[n - i];
        if (used[v])
            continue;
        dfs2(v);
        countOfComponents++;
        //std::cout << "New Compopent ";
        //for (int x : component)
        //    std::cout << x << " ";
        //std::cout << std::endl;
        component.clear();
    }
    return countOfComponents;
}