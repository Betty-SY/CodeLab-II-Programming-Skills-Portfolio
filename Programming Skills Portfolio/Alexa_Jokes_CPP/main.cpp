#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>
int main() {
    std::ifstream file("randomJokes.txt");
    if (!file) { std::cerr << "Cannot open randomJokes.txt\n"; return 1; }
    std::vector<std::string> jokes;
    std::string line;
    while (std::getline(file, line)) if (!line.empty()) jokes.push_back(line);
    if (jokes.empty()) { std::cerr << "No jokes found\n"; return 1; }
    std::mt19937 engine(std::random_device{}());
    std::uniform_int_distribution<size_t> choose(0, jokes.size() - 1);
    char again = 'y';
    while (again == 'y' || again == 'Y') {
        std::cout << "Alexa says: " << jokes[choose(engine)] << "\nAnother? (y/n): ";
        std::cin >> again;
    }
}
