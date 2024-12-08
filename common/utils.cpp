#include "utils.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

std::vector<std::string> readLinesFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Could not open file: " + filename);
    }
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    return lines;
}

int countOccs(std::string input, std::string subString)
{
    int occs = 0;
    std::string::size_type pos = 0;
    while ((pos = input.find(subString, pos)) != std::string::npos)
    {
        occs++;
        pos += input.length();
    }
    return occs;
}