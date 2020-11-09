#include "DeepthSearchSolve.h"

DeepthSearchSolve::DeepthSearchSolve(TaskGenerator task)
{
    
}

DeepthSearchSolve::DeepthSearchSolve(int n, std::vector<int> matrix)
{
    setCountOfVertex_N(n);
    resizeMatrix();
    setMatrix(matrix);
    setGraphAndReverseGraph(n);
}

void DeepthSearchSolve::resizeMatrix()
{
    _matrix.resize(getCountOfVertex_N() + 1);
}

void DeepthSearchSolve::setMatrix(std::vector<int> matrix)
{
    for (int i = 1; i <= getCountOfVertex_N(); i++)
    {
        _matrix[i].push_back(matrix[i]);
    }
}

void DeepthSearchSolve::setGraphAndReverseGraph(int n)
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

std::vector<int> DeepthSearchSolve::deepthFirstSearch1(int v)
{
    used[v] = true;
    for (int to : _graph[v])
    {
        if (!used[to])
        {
            deepthFirstSearch1(to);
        }
    }
    order.push_back(v);
    return order;
}

std::vector<int> DeepthSearchSolve::deepthFirstSearch2(int v)
{
    used[v] = true;
    component.push_back(v);
    for (int to : _graph_reverse[v])
    {
        if (!used[to])
        {
            deepthFirstSearch2(to);
        }
    }
    return component;
}

void DeepthSearchSolve::solve()
{
    used.assign(getCountOfVertex_N() + 1, false);
    for (int i = 1; i < getCountOfVertex_N(); i++)
    {
        if (!used[i])
        {
            deepthFirstSearch1(i);
        }
    }

    used.assign(getCountOfVertex_N() + 1, false);

    for (int i = order.size() - 1; i >= 0; i--)
    {
        int v = order[i];
        if (used[v])
            continue;
        deepthFirstSearch2(v);

        for (int x : component)
        {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
}
