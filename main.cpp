#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {
    std::cout << "Hello, World! We meet again!" << std::endl;
    const std::string programName(argv[0]);
    if (argc != 2) {
        std::cerr << "Usage: " << programName << " <filename>\n";
        return 1;
    }
    const std::string fileName(argv[1]);
    std::ifstream file(fileName);
    if (! file.is_open()) {
        std::cerr << "Could not open the file " << fileName << std::endl;
        return 1;
    }
    int lineCount = 0;
    std::string line;
    while(getline(file, line)) {
        lineCount++;
    }
    std::cout << lineCount << std::endl;

    file.close();
    return 0;
}

/*
 * Example Usage: ccwc -c file.txt
 * Commandline options:
 * -c : return the count of characters in input file
 * file.txt : input file to check
 */

