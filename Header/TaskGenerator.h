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
    std::vector<std::pair<int, int>> graph;

    std::map<std::pair<int, int>, bool> mp;
    int Randomizator(int min, int max);
    void generateGraph();

public:
    int get_N();
    std::vector<std::pair<int, int>> get_Graph();
    TaskGenerator();
    TaskGenerator(int n);
    ~TaskGenerator() = default;
};
