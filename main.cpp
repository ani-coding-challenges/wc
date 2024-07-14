#include <fstream>
#include <iostream>
#include <filesystem>

int main(int argc, char *argv[]) {
    std::cout << "Hello, World! We meet again!" << std::endl;
    std::filesystem::path cwd = std::filesystem::current_path();
    std::cout << "cwd: " << cwd.string() << std::endl;
    const std::string programName(argv[0]);
    if (argc != 2) {
        std::cerr << "Usage: " << programName << " <filename>\n";
        return 1;
    }
    const std::string fileName(argv[1]);
    std::cout << "File: " << fileName << std::endl;
    std::ifstream file(fileName);
    if (! file.is_open()) {
        std::cerr << "Could not open the file " << fileName << std::endl;
        return 1;
    }
    auto fileSize = std::filesystem::file_size(fileName);
    std::cout << fileSize << std::endl;
    int lineCount = 0;
    int wordCount = 0;
    std::size_t charCount = 0;
    std::string line;
    std::string word;
    while(getline(file, line)) {
        lineCount++;
        std::stringstream ss(line);
        while(ss >> word) {
            wordCount++;
        }
        charCount += line.length();
    }
    std::cout << charCount << std::endl;
    std::cout << wordCount << std::endl;
    std::cout << lineCount << std::endl;

    file.close();
    file.open(fileName); // open the file again to read from start
    char c;
    int charCount1 = 0;
    int allCharCount = 0;
    while(file.get(c)) {
        // UTF-8 allows multi-byte characters. Count only the starting byte for each character to get accurate -m count
        // https://stackoverflow.com/a/3586973
        if ((c & 0xc0) != 0x80) {
            charCount1++;
        }
        allCharCount++;
    }
    std::cout << allCharCount << std::endl;
    std::cout << charCount1 << std::endl;

    return 0;
}

/*
 * Example Usage: ccwc -c file.txt
 * Commandline options:
 * -c : return the count of characters in input file
 * file.txt : input file to check
 */

