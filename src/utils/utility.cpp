#include "utils/utility.hpp"

std::string ReadFile(std::string file, bool addLineTerminator) {
    ifstream f(file);
    std::string currentLine;
    std::string allFileContent;
    while (getline(f, currentLine)) {
        if (addLineTerminator) {
            currentLine += "\n";
        }
        allFileContent += currentLine;
    }
    f.close();
    return allFileContent;
}

// Found how to do this from https://www.oreilly.com/library/view/c-cookbook/0596007612/ch10s07.html
long GetFileModTime(std::string file) {
    struct stat fileInfo;
    stat(file.c_str(), &fileInfo);
    return fileInfo.st_mtime;
}