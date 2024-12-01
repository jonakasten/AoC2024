#include <iostream>
#include "utils.h"
#include <sstream>
#include <algorithm>
#include <numeric>

void solve(std::vector<std::string> lines) 
{
    std::vector<int> firstList, secondList;
    int num1, num2;

    for (std::string &line : lines)
    {
       std::istringstream ss(line);
       ss >> num1 >> num2;
       firstList.push_back(num1);
       secondList.push_back(num2);
    }

    std::sort(firstList.begin(), firstList.end());
    std::sort(secondList.begin(), secondList.end());

    std::vector<int> distances;
    for (int i = 0; i < firstList.size(); i++)
    {
        distances.push_back(abs(firstList[i] - secondList[i]));
    }

    //for (int num1 : firstList) 
    //{
    //    std::cout << num1 << "\n";
    //}

    //std::cout << "======\n";

    //for (int num2 : secondList) 
    //{
    //    std::cout << num2 << "\n";
    //}

    //for (int distance : distances)
    //{
    //    std::cout << distance << "\n";
    //}
    int totalDistance = std::accumulate(distances.begin(), distances.end(), 0);
    std::cout << totalDistance << "\n";
}

int main() 
{
    try 
    {
        std::vector<std::string> lines = readLinesFromFile("./day01/input.txt");
        // handle input
        solve(lines);
    } 
    catch (const std::exception &ex)
    {
        std::cerr << "Error: " << ex.what() << std::endl;
        return 1;
    }
    return 0;
}