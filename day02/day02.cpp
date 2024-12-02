#include "utils.h"
#include<bits/stdc++.h>

void solve1(std::vector<std::string> lines)
{
    int safeSum = 0;

    for(auto &line : lines)
    {
        std::istringstream ss(line);
        std::vector<int> report;
        int num;
        int prev = -1;
        while(ss >> num)
        {
            report.push_back(num);
        }


        bool isSafe = true;
        bool increase = report[1] > report[0];
        for (size_t i = 1; i < report.size(); i++)
        {
            int current = report[i];
            int prev = report[i-1];
            if (current == prev)
            {
                isSafe = false;
                break;
            }
            if (current > prev)
            {
                if (!increase) 
                {
                    isSafe = false;
                    break;
                }
            }
            else if (current < prev)
            {
                if(increase)
                {
                    isSafe = false;
                    break;
                }
            }

            int distance = abs(current - prev);
            if (distance > 3)
            {
                isSafe = false;
                break;
            } 
        }
        safeSum += isSafe? 1 : 0;
    }
    std::cout << safeSum << "\n";
}

int main() 
{
    try 
    {
        std::vector<std::string> lines = readLinesFromFile("./day02/input.txt");
        // handle input
        solve1(lines);
        //solve2(lines);
    } 
    catch (const std::exception &ex)
    {
        std::cerr << "Error: " << ex.what() << std::endl;
        return 1;
    }
    return 0;
}