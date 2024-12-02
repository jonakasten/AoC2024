#include "utils.h"

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <map>

void solve1(std::vector<std::string> lines) 
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
    int totalDistance = std::accumulate(distances.begin(), distances.end(), 0);
    std::cout << totalDistance << "\n";
}

void solve2(std::vector<std::string> lines) 
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

    std::map<int,int> occFirst;
    for (int firstNum : firstList)
    {
        occFirst[firstNum]++;
    }

    std::map<int,int> occSecond;
    for (int secondNum : secondList)
    {
        occSecond[secondNum]++;
    }

    int simScore = 0;
    for (auto &firstOcc : occFirst)
    {
        int occInSecondList = occSecond[firstOcc.first];
        int increment = occInSecondList * firstOcc.first * firstOcc.second;
        simScore += increment;
    }

    std::cout << simScore << "\n";
}

int main() 
{
    try 
    {
        std::vector<std::string> lines = readLinesFromFile("./day01/input.txt");
        // handle input
        //solve1(lines);
        solve2(lines);
    } 
    catch (const std::exception &ex)
    {
        std::cerr << "Error: " << ex.what() << std::endl;
        return 1;
    }
    return 0;
}