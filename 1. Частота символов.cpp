#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

static bool sortValue(const std::pair<char, int>& a, const std::pair<char, int>& b)
{
    return a.second > b.second;
}

int main() 
{
    std::string input;
    std::cout << "Введите текст: ";
    std::getline(std::cin, input);

    std::map<char, int> frequencies;

    for (char c : input) 
    {
        if (std::isalpha(c)) 
        {
            frequencies[std::tolower(c)]++;
        }
    }

    std::vector<std::pair<char, int>> sortedFrequencies(frequencies.begin(), frequencies.end());

    std::sort(sortedFrequencies.begin(), sortedFrequencies.end(), sortValue);

    for (const auto& pair : sortedFrequencies) 
    {
        std::cout << pair.first << ": " << pair.second << "\n";
    }

    return 0;
}