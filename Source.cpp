#include "functions.h"
#include "inputFile.h"
#include <iostream>

int main() {
    output(std::cout, "../../../head.txt");
    bool open = 1;
    while (open) {
        std::string expression;
        std::getline(std::cin, expression);
        if (expression == "Q") {
            open = 0;
            continue;
        } else if (expression == "HELP") {
            output(std::cout, "../../../help.txt");
            continue;
        } else {
            try {
                std::cout << solution(expression) << '\n';
            } catch (std::invalid_argument except) {
                std::cout << except.what() << '\n';
            } catch (std::runtime_error except) {
                std::cout << except.what() << '\n';
            }
        }
    }
}
