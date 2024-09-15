#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

// Reverse the contents of a file
void reverseFileContent(const std::string& inputFilePath, const std::string& outputFilePath) {
    std::ifstream inputFile(inputFilePath);
    std::string content;

    // Read the file content
    inputFile.seekg(0, std::ios::end);
    content.reserve(inputFile.tellg());
    inputFile.seekg(0, std::ios::beg);

    content.assign((std::istreambuf_iterator<char>(inputFile)),
                    std::istreambuf_iterator<char>());

    inputFile.close();

    // Reverse the content
    std::reverse(content.begin(), content.end());

    std::ofstream outputFile(outputFilePath);
    outputFile << content;
    outputFile.close();
}

int main() {
    std::string filePath = "C:\\Users\\danie\\CSC450_CT5_mod5.txt";
    std::string reverseFilePath = "C:\\Users\\danie\\CSC450-mod5-reverse.txt";

    // Append user input to the file
    std::ofstream outFile(filePath, std::ios::app); // open in append mode
    std::string userInput;

    std::cout << "Enter text to append to the file: ";
    std::getline(std::cin, userInput);

    outFile << userInput << std::endl;
    outFile.close();

    // Reverse the file contents and save to the reverse file
    reverseFileContent(filePath, reverseFilePath);

    std::cout << "Text appended to " << filePath << " and reversed content stored in " << reverseFilePath << std::endl;

    return 0;
}