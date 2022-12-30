#include "functions.h"
#include "inputFile.h"
#include <iostream>

int main() {
    output(std::cout, "../../../head.txt");
    bool open = 1;
    std::string mode = "INT";
    while (open) {
        std::string expression;
        std::getline(std::cin, expression);
        if (expression == "Q") {
            open = 0;
            continue;
        } else if (expression == "HELP") {
            output(std::cout, "../../../help.txt");
            continue;
        } else if (expression == "INT") {
            mode = "INT";
        } else if (expression == "DOUBLE") {
            mode = "DOUBLE";
        } else {
            try {
                if (mode == "INT") {
                    std::cout << solution<long long>(expression) << '\n';
                } else {
                    std::cout << solution<double>(expression) << '\n';
                }
            } catch (std::invalid_argument except) {
                std::cout << except.what() << '\n';
            } catch (std::runtime_error except) {
                std::cout << except.what() << '\n';
            }
        }
    }
}
