#include "utils.h"
#include<bits/stdc++.h>


void solve1(std::vector<std::string> lines) 
{
    // search for X
    // 
    int xmasCnt = 0;
    size_t totalSize = lines.size();
    for(size_t i = 0; i < totalSize; i++)
    {
        xmasCnt += countOccs(lines[i], "XMAS");
        xmasCnt += countOccs(lines[i], "SAMX");
        for(size_t j = 0; j < lines[i].length(); j++)
        {
            if (lines[i][j] == 'X')
            {
                int remainingLen = lines[i].length() - j;
                int remainingHeight = totalSize - i;

                //bool enoughRemain = remainingLen >= 3;
                //bool enoughPrev = j >= 3;
                //bool enoughRemainHeight = remainingHeight >= 3;
                //bool enoughPrevHeight = i >= 3;
                
                bool enoughRemain = (j + 3 < lines[i].length());
                bool enoughPrev = (j >= 3);
                bool enoughRemainHeight = (i + 3 < totalSize);
                bool enoughPrevHeight = (i >= 3);

                if (enoughRemainHeight && enoughRemain) // bottom right
                {
                    std::string searchString;
                    searchString.append(1, lines[i][j]);
                    searchString.append(1, lines[i+1][j+1]);
                    searchString.append(1, lines[i+2][j+2]);
                    searchString.append(1, lines[i+3][j+3]);
                    xmasCnt += searchString == "XMAS"? 1 : 0;
                }
                if (enoughRemainHeight && enoughPrev) // bottom left
                {
                    std::string searchString;
                    searchString.append(1, lines[i][j]);
                    searchString.append(1, lines[i+1][j-1]);
                    searchString.append(1, lines[i+2][j-2]);
                    searchString.append(1, lines[i+3][j-3]);
                    xmasCnt += searchString == "SAMX"? 1 : 0;
                }
                if (enoughPrevHeight && enoughPrev) // top left
                {
                    std::string searchString;
                    searchString.append(1, lines[i][j]);
                    searchString.append(1, lines[i-1][j-1]);
                    searchString.append(1, lines[i-2][j-2]);
                    searchString.append(1, lines[i-3][j-3]);
                    xmasCnt += searchString == "SAMX"? 1 : 0;
                }
                if (enoughPrevHeight && enoughRemain) // top right
                {
                    std::string searchString;
                    searchString.append(1, lines[i][j]);
                    searchString.append(1, lines[i-1][j+1]);
                    searchString.append(1, lines[i-2][j+2]);
                    searchString.append(1, lines[i-3][j+3]);
                    xmasCnt += searchString == "XMAS"? 1 : 0;
                }
                if (enoughPrevHeight)
                {
                    std::string searchString;
                    searchString.append(1, lines[i][j]);
                    searchString.append(1, lines[i-1][j]);
                    searchString.append(1, lines[i-2][j]);
                    searchString.append(1, lines[i-3][j]);
                    xmasCnt += searchString == "SAMX"? 1 : 0;
                }
                if (enoughRemainHeight)
                {
                    std::string searchString;
                    searchString.append(1, lines[i][j]);
                    searchString.append(1, lines[i+1][j]);
                    searchString.append(1, lines[i+2][j]);
                    searchString.append(1, lines[i+3][j]);
                    xmasCnt += searchString == "XMAS"? 1 : 0;
                }
            }
        }
        std::cout << "count: " << xmasCnt << "\n";
    }
    std::cout << xmasCnt << "\n";
}

int main() 
{
    try 
    {
        std::vector<std::string> lines = readLinesFromFile("./day04/test_input.txt");
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