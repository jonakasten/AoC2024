#include "utils.h"
#include<bits/stdc++.h>

void solve1(std::vector<std::string> lines)
{
    std::regex regex_pattern(R"(mul\((-?\d+),(-?\d+)\))"); 

    int sumOfProds =00;

    for(auto &line : lines)
    {
        std::sregex_iterator begin(line.begin(), line.end(), regex_pattern);
        std::sregex_iterator end;

        for (std::sregex_iterator i = begin; i != end; i++)
        {
            std::smatch match = *i;
            int x = std::stoi(match[1].str());
            int y = std::stoi(match[2].str());
            sumOfProds += (x * y);
        }
    }
    std::cout << sumOfProds << "\n";
}

int main() 
{
    try 
    {
        std::vector<std::string> lines = readLinesFromFile("./day03/input.txt");
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