#pragma once
#include <iostream>
#include <string>
#include <fstream>

 std::ostream& output(std::ostream& out, const std::string& pathName, const char delimeter = '\n') {
	std::ifstream fin(pathName);
    std::string str;
    while (!fin.eof()) {
        std::getline(fin, str, delimeter);
        out << str << delimeter;
    }

	fin.close();
    return out;
}

