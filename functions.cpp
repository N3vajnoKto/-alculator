#include "functions.h"

int sum(int a, int b) {
    return a + b;
}

double sum(double a, double b) {
    return a + b;
}

int sub(const int a, const int b) {
    return a - b;
}

double sub(const double a, const double b) {
    return a - b;
}

int mult(const int a, const int b) {
    return a * b;
}

double mult(const double a, const double b) {
    return a * b;
}

int division(const int a, const int b) {
    return a / b;
}

double division(const double a, const double b) {
    return a / b;
}

int mod(const int a, const int b) {
    return a % b;
}

int negation(const int a) {
    if (a == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int conjunction(const int a, const int b) {
    return (a & b);
}

int disjunction(const int a, const int b) {
    return (a | b);
}

int exclusiveOr(const int a, const int b) {
    return (a ^ b);
}

int leftShift(const int a, const int k) {
    return (a << k);
}

int rightShift(const int a, const int k) {
    return (a >> k);
}

int unarySum(const int a) {
    return (a + 1);
};

int unarySub(const int a) {
    return (a - 1);
};

operation askForOperation(std::string type) {
    std::string menu;
    if (type == "int") {
        menu = "Sum - 0\nSub - 1\nMult - 2\nDivision - 3\nMod - 4\nConjunction - 5\n";
        menu += "Disjunction - 6\nExclusiveOr - 7\nLeftShift - 8\nRightShift - 9\n";
        menu += "Plus one - 101\nMinus one - 102\nNegation - 103\n";
    }
    else if (type == "double") {
        menu = "Sum - 0\nSub - 1\nMult - 2\nDivision - 3";
    }

    std::cout << menu << std::endl;
    std::cout << "Print operation: ";
    int num;
    std::cin >> num;
    return static_cast<operation>(num);
}

bool isUnary(operation& a) {
    return a >= 100;
}

void askForNumber(int& a) {
    std::cout << "input 1 integer: ";
    std::cin >> a;
}

void askForNumber(int& a, int& b) {
    std::cout << "input 2 integer: ";
    std::cin >> a >> b;
}

void askForNumber(double& a) {
    std::cout << "input 1 integer: ";
    std::cin >> a;
}

void askForNumber(double& a, double& b) {
    std::cout << "input 2 integer: ";
    std::cin >> a >> b;
}

void applyUnaryOperation(const operation& op, const int a, int& b) {
    switch (op) {
    case UnarySum: {
        b = unarySum(a);
        break;
    }
    case UnarySub: {
        b = unarySub(a);
        break;
    }
    case (Negation): {
        b = negation(a);
        break;
    }
    case Empty: {
        break;
    }
    default: {
        std::cout << "Wrong! Operation is not from the list" << std::endl;
        break;
    }
    }
    return;
}

void applyUnaryOperation(const operation& op, const double a, double& b) {
    switch (op) {
    case Empty: {
        break;
    }
    default: {
        std::cout << "Wrong! Operation is not from the list" << std::endl;
        break;
    }
    }
    return;
}

void applyBinaryOperation(
    const operation& op, const int a, const int b, int& c
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
    case (Conjunction): {
        c = conjunction(a, b);
        break;
    }
    case (Disjunction): {
        c = disjunction(a, b);
        break;
    }
    case (ExclusiveOr): {
        c = exclusiveOr(a, b);
        break;
    }
    case (LeftShift): {
        c = leftShift(a, b);
        break;
    }
    case (RightShift): {
        c = rightShift(a, b);
        break;
    }
    default: {
        std::cout << "Wrong! Operation is not from the list" << std::endl;
        break;
    }
    }
    return;
}

void applyBinaryOperation(
    const operation& op, const double a, const double b, double& c
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
        std::cout << "Wrong! Operation is not from the list" << std::endl;
        break;
    }
    }
    return;
}