#include <iostream>

long long sum(const long long&, const long long&);
long long sub(const long long&, const long long&);
long long mult(const long long&, const long long&);
long long division(const long long&, const long long&);
long long mod(const long long&, const long long&);

long double division(const long double&, const long double&);
long double sum(const long double&, const long double&);
long double sub(const long double&, const long double&);
long double mult(const long double&, const long double&);

enum operation { Sum, Sub, Mult, Division, Mod, Exp = 100, Empty = 1000 };

bool isUnary(operation&);
void askForNumber(long long&);
void askForNumber(long long&, long long&);
void askForNumber(long double&);
void askForNumber(long double&, long double&);

void applyUnaryOperation(const operation&, const long long&, long long&);
void applyUnaryOperation(const operation&, const long double&, long double&);
void applyBinaryOperation(const operation&, const long long&, const long long&, long long&);
void applyBinaryOperation(const operation&, const long double&, const long double&, long double&);


operation askForOperation();

int main() {
    while (true) {
        std::string varType;
        std::cout << "which type?" << std::endl;

        std::cin >> varType;

        if (varType == "int") {
            operation op;
            op = askForOperation();
            if (isUnary(op)) {
                long long x;
                askForNumber(x);
                long long result;
                applyUnaryOperation(op, x, result);
                std::cout << result << std::endl;
            } else {
                long long x, y;
                askForNumber(x, y);
                long long result;
                applyBinaryOperation(op, x, y, result);

                std::cout << result << std::endl;
            }

        } else {
            operation op;
            op = askForOperation();
            if (isUnary(op)) {
                long double x;
                askForNumber(x);
                long double result;
                applyUnaryOperation(op, x, result);
                std::cout << result << std::endl;
            } else {
                long double x, y;
                askForNumber(x, y);
                long double result;
                applyBinaryOperation(op, x, y, result);

                std::cout << result << std::endl;
            }
        }
    }
}

long long sum(const long long& a, const long long& b) {
    return a + b;
}

long double sum(const long double& a, const long double& b) {
    return a + b;
}

long long sub(const long long& a, const long long& b) {
    return a - b;
}

long double sub(const long double& a, const long double& b) {
    return a - b;
}

long long mult(const long long& a, const long long& b) {
    return a * b;
}

long double mult(const long double& a, const long double& b) {
    return a * b;
}

long long division(const long long& a, const long long& b) {
    return a / b;
}

long double division(const long double& a, const long double& b) {
    return a / b;
}

long long mod(const long long& a, const long long& b) {
    return a % b;
}

operation askForOperation() {
    std::string menu = "Sum - 0\nSub - 1\nMult - 2\nDivision - 3\nMod - 4\n";
    std::cout << menu;
    std::cout << "operation? ";
    int num;
    std::cin >> num;
    // return operation(num);
    return static_cast<operation>(num);
}

bool isUnary(operation& a) {
    return a >= 100;
}

void askForNumber(long long& a) {
    std::cout << "input 1 integer: ";
    std::cin >> a;
}

void askForNumber(long long& a, long long& b) {
    std::cout << "input 2 integer: ";
    std::cin >> a >> b;
}

void askForNumber(long double& a) {
    std::cout << "input 1 integer: ";
    std::cin >> a;
}

void askForNumber(long double& a, long double& b) {
    std::cout << "input 2 integer: ";
    std::cin >> a >> b;
}

void applyUnaryOperation(const operation& op, const long long& a, long long& b) {
    switch (op) {
        case Empty: {
            break;
        }
        default: {
            std::cout << "Wrong!!!" << std::endl;
            break;
        }
    }
    return;
}

void applyUnaryOperation(const operation& op, const long double& a, long double& b) {
    switch (op) {
        case Empty: {
            break;
        }
        default: {
            std::cout << "Wrong!!!" << std::endl;
            break;
        }
    }
    return;
}

void applyBinaryOperation(
    const operation& op, const long long& a, const long long& b, long long& c
) {
    switch (op) {
        case (Sum): {
            c = sum(a, b);
            break;
        }
        case (Sub): {
            c = sub(a, b);
            break;
        }
        case (Mult): {
            c = mult(a, b);
            break;
        }
        case (Division): {
            c = division(a, b);
            break;
        }
        case (Mod): {
            c = mod(a, b);
            break;
        }
        default: {
            std::cout << "Wrong!!!" << std::endl;
            break;
        }
    }
    return;
}

void applyBinaryOperation(
    const operation& op, const long double& a, const long double& b, long double& c
) {
    switch (op) {
        case (Sum): {
            c = sum(a, b);
            break;
        }
        case (Sub): {
            c = sub(a, b);
            break;
        }
        case (Mult): {
            c = mult(a, b);
            break;
        }
        case (Division): {
            c = division(a, b);
            break;
        }
        default: {
            std::cout << "Wrong!!!" << std::endl;
            break;
        }
    }
    return;
}
