#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

template<typename type>
void output(std::vector<type>& v, const std::string& pathName, const std::string& delimeter) {
	std::ofstream fout(pathName);

	for (auto& to : v) {
		fout << to << delimeter;
	}

	fout.close();
}

template<typename type>
void input(std::vector<type>& v, const std::string& pathName, const std::string& delimeter) {
	std::ifstream fin(pathName, std::ios::in);

	std::string str;

	v = {};

	while (std::getline(fin, str)) {
		std::istringstream ss(str);

		std::string tmp;
		while (std::getline(ss, tmp, *(delimeter.c_str()))) {
			type element;
			std::istringstream newss(tmp);
			newss >> element;
			v.push_back(element);
		}
	}
	fin.close();
}
