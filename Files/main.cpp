#include <iostream>
#include "TaskGenerator.h"
#include "ConnectedGraph.h"
#include "DeepthSearchSolve.h"
#include "UnOptimizedSolve.h"
#include <fstream>

TaskGenerator *test1 = new TaskGenerator();
int testUnOptimizedSolve()
{
    ConnectedGraph *versionSimple = new UnOptimizedSolve(test1);
    std::cout << "N: " << test1->get_N() << std::endl;
    unsigned int timeStart = clock();
    int result = versionSimple->solve();
    unsigned int timeEnd = clock();

    double time = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;

    std::cout << "result: " << result << std::endl;
    std::cout << "time: " << time << std::endl;
    return 1;
}

int testDepthSearchSolve()
{
    ConnectedGraph *versionOptimized = new DeepthSearchSolve(test1);
    std::cout << "N: " << test1->get_N() << std::endl;

    unsigned int timeStart = clock();
    int result = versionOptimized->solve();
    unsigned int timeEnd = clock();

    double time = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;

    std::cout << "result: " << result << std::endl;
    std::cout << "time: " << time << std::endl;
    return 1;
}

int testExcellTable()
{
    std::cout << "Excel Table Test" << std::endl;

    std::ofstream ExcelFile;

    ExcelFile.open("D:\\projects\\CCGraph\\Table\\Table.csv");
    if (ExcelFile.is_open())
    {
        ExcelFile << "N ;"
                  << "result simple ;"
                  << "time simple ;"
                  << ";"
                  << "result optimized ;"
                  << "time optimized ;"
                  << std::endl;

        for (int i = 500; i <= 10000; i += 500)
        {
            TaskGenerator *test2 = new TaskGenerator(i);
            ConnectedGraph *versionSimple = new UnOptimizedSolve(test2);
            ConnectedGraph *versionOptimized = new DeepthSearchSolve(test2);

            std::cout << "N: " << test2->get_N() << std::endl;

            unsigned int timeStartOne = clock();
            int result1 = versionSimple->solve();
            unsigned int timeEndOne = clock();

            unsigned int timeStartTwo = clock();
            int result2 = versionOptimized->solve();
            unsigned int timeEndTwo = clock();

            double timeOne = (double)(timeEndOne - timeStartOne) / CLOCKS_PER_SEC;
            double timeTwo = (double)(timeEndTwo - timeStartTwo) / CLOCKS_PER_SEC;

            std::cout << "result simple: " << result1 << "\t";
            std::cout << "time simple: " << timeOne << "\t";
            std::cout << "result optimized: " << result2 << "\t";
            std::cout << "time optimized: " << timeTwo << std::endl;
            std::cout << std::endl;
            ExcelFile << test2->get_N() << ";"
                      << result1 << ";"
                      << timeOne << ";"
                      << ";"
                      << result2 << ";"
                      << timeTwo << ";"
                      << std::endl;
            delete versionSimple;
            delete versionOptimized;
            delete test2;
        }
    }
    return 1;
}

int main()
{
    testExcellTable();
    //testUnOptimizedSolve();
    //testDepthSearchSolve();
    //delete test1;
    system("pause>nul");
    return 0;
}