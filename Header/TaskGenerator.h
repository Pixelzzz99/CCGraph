#pragma once
#include <utility>
#include <vector>
#include <map>
#include <ctime>
#include <cstdlib>

class TaskGenerator
{
private:
    int n;
    int m;
    std::vector<std::pair<int, int>> graph;

    std::map<std::pair<int, int>, bool> mp;
    int Randomizator(int min, int max);
    void generateGraph();

public:
    int get_N();
    int get_M();
    std::vector<std::pair<int, int>> get_Graph();
    TaskGenerator();
    ~TaskGenerator() = default;
};
