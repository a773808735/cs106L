#include <cmath>    // for sqrt
#include <iostream> // to print
#include <utility>  // for pairs
#include <vector>
#include <fstream>
#include <string>
#include <map>
const char delimeter = ',';
std::map<std::string, std::pair<std::string, int>> createMap(std::string &filename);
void printMap(std::map<std::string, std::pair<std::string, int>> csmap_);
int main()
{
    std::string filename = "D:/C++/CS106L/lectures/lecture6_exercise_w23.csv";
    auto csmap = createMap(filename);
    printMap(csmap);
    return 0;
}
std::map<std::string, std::pair<std::string, int>> createMap(std::string &filename)
{
    std::map<std::string, std::pair<std::string, int>> csmap;
    std::ifstream ifs(filename);
    if (ifs.is_open())
    {
        std::string line = "";
        while (std::getline(ifs, line))
        {
            auto first_pos = line.find(delimeter);
            auto second_pos = line.find(delimeter, first_pos + 1);
            csmap[line.substr(0, first_pos)] = std::make_pair(line.substr(first_pos + 1, second_pos - first_pos - 1), std::stoi(line.substr(second_pos + 1)));
        }
    }
    ifs.close();
    return csmap;
}
void printMap(std::map<std::string, std::pair<std::string, int>> csmap_)
{
    for (auto it = csmap_.begin(); it != csmap_.end(); ++it)
    {
        std::cout << "name is:" << it->first << " school is:" << it->second.first << " year is: " << it->second.second;
        std::cout << "\n";
    }
}