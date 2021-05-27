#include "utils/utility.hpp"

bool ReadFile(std::string file, std::string& fileContents, bool addLineTerminator) {
    ifstream f(file);
    std::string currentLine;
    std::string allFileContent;

    if (f.is_open()) {
        while (getline(f, currentLine)) {
            if (addLineTerminator) {
                currentLine += "\n";
            }
            allFileContent += currentLine;
        }
        f.close();
        fileContents = allFileContent;
        return true;
    }
    else {
        return false;
    }
}

// Found how to do this from https://www.oreilly.com/library/view/c-cookbook/0596007612/ch10s07.html
long GetFileModTime(std::string file) {
    struct stat fileInfo;
    stat(file.c_str(), &fileInfo);
    return fileInfo.st_mtime;
}