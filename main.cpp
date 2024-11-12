#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

void readFile(const std::string& filename, std::vector<std::string>& lines) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
}

void writeFile(const std::string& filename, const std::vector<std::string>& lines) {
    std::ofstream file(filename);
    for (const auto& line : lines) {
        file << line << std::endl;
    }
}

int main() {
    std::vector<std::string> surnames, names, patronymics;
    readFile("Ï.txt", surnames);
    readFile("².txt", names);
    readFile("Á.txt", patronymics);

    if (surnames.size() != names.size() || names.size() != patronymics.size()) {
        std::cerr << "Error: The number of lines in the files do not match." << std::endl;
        return 1;
    }

    std::vector<std::string> fullNames;
    for (size_t i = 0; i < surnames.size(); ++i) {
        fullNames.push_back(surnames[i] + " " + names[i] + " " + patronymics[i]);
    }

    std::sort(fullNames.begin(), fullNames.end());

    writeFile("report.txt", fullNames);

    return 0;
}
