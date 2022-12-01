#include <iostream>
#include "inputFile.h"
#include "functions.h"

int main() {
    while (true) {
        std::string varType;
        std::cout << "Print type or 'stop' to end: ";

        std::cin >> varType;

		if (varType == "stop") {
			break;
		}

        if (varType == "int") {
            operation op;
            op = askForOperation(varType);
            if (isUnary(op)) {
                int x;
                askForNumber(x);
                int result;
                applyUnaryOperation(op, x, result);
                std::cout << result << std::endl;
            } else {
                int x, y;
                askForNumber(x, y);
                int result;
                applyBinaryOperation(op, x, y, result);

                std::cout << result << std::endl;
            }

        } else if (varType == "double") {
            operation op;
            op = askForOperation(varType);
            if (isUnary(op)) {
                double x;
                askForNumber(x);
                double result;
                applyUnaryOperation(op, x, result);
                std::cout << result << std::endl;
            } else {
                double x, y;
                askForNumber(x, y);
                double result;
                applyBinaryOperation(op, x, y, result);

                std::cout << result << std::endl;
            }
        } else {
            std::cout << "Wrong type!" << std::endl;
        }
    }
}
