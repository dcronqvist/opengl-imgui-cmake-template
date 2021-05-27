#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <sys/types.h>
#include <sys/stat.h>
#include <cerrno>
using namespace std;

bool ReadFile(std::string file, std::string& fileContents, bool addLineTerminator = false);
long GetFileModTime(std::string file);