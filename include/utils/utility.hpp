#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <sys/types.h>
#include <sys/stat.h>
#include <cerrno>
using namespace std;

std::string ReadFile(std::string file, bool addLineTerminator = false);
long GetFileModTime(std::string file);