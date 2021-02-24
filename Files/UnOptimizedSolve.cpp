#include "UnOptimizedSolve.h"

UnOptimizedSolve::UnOptimizedSolve(TaskGenerator *task)
{
    setCountOfVertex_N(task->get_N());
    resizeRosters();
    //TODO set Graph from TaskGenerator
}

UnOptimizedSolve::UnOptimizedSolve(int n, std::vector<int> matrix)
{
    setCountOfVertex_N(n);
    resizeRosters();
    resizeMatrix();
    setMatrix(matrix);
    setGraphAndReverseGraph(n);
}

void UnOptimizedSolve::resizeRosters()
{
    RosterOne.resize(getCountOfVertex_N());
    RosterTwo.resize(getCountOfVertex_N());
    for (int i = 0; i < getCountOfVertex_N(); i++)
    {
        RosterOne[i].resize(getCountOfVertex_N());
        RosterTwo[i].resize(getCountOfVertex_N());
    }
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
        if (!RosterOne[v][i] || used[i])
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
        if (!RosterTwo[v][i] || used[i])
            continue;
        dfs2(i);
    }
}

void UnOptimizedSolve::solve()
{
    int n = getCountOfVertex_N();
    for (int i = 1; i <= n; i++)
        if (!used[i])
            dfs1(i);
    for (int i = 1; i <= n; i++)
        used[i] = false;

    for (int i = 1; i <= n; i++)
    {
        int v = order[n - i];
        if (!used[v])
            dfs2(v);
        std::cout << "New Compopent ";
        for (int x : component)
            std::cout << x << " ";
        std::cout << std::endl;
        component.clear();
    }
}