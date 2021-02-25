#include "TaskGenerator.h"

TaskGenerator::TaskGenerator()
{
    srand(time(nullptr));
    n = Randomizator(1, 100);
    generateGraph();
}

TaskGenerator::TaskGenerator(int n)
{
    this->n = n;
    generateGraph();
}

int TaskGenerator::Randomizator(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void TaskGenerator::generateGraph()
{
    std::vector<int> v = {1};
    int id_v = 2;
    int count_d = n - 1;
    while (count_d > 0)
    {
        int position = Randomizator(0, v.size() - 1);
        int now_v = v[position];
        v.push_back(id_v);
        graph.push_back({now_v, id_v});
        mp[{now_v, id_v}] = 1;
        id_v++;
        count_d--;
    }
    
    int m = n - 1;
    int it = Randomizator(0, 100);
    while (it--)
    {
        int pos1 = Randomizator(0, v.size() - 1);
        int pos2 = Randomizator(0, v.size() - 1);
        if (pos1 == pos2)
            continue;
        int v1 = v[pos1], v2 = v[pos2];
        if (mp.count({v1, v2}))
            continue;
        mp[{v1, v2}] = 1;
        graph.push_back({v1, v2});
        m++;
    }
    for (int i = 0; i < graph.size(); i++)
    {
        if (rand() % 2)
            std::swap(graph[i].first, graph[i].second);
    }
}

int TaskGenerator::get_N()
{
    return n;
}

std::vector<std::pair<int, int>> TaskGenerator::get_Graph()
{
    return graph;
}