#pragma once

enum operation {
    Error = -1,
    Sum,
    Sub,
    Mult,
    Division,
    Mod,
    Conjunction,
    Disjunction,
    ExclusiveOr,
    LeftShift,
    RightShift,
    Exp = 100,
    UnarySum,
    UnarySub,
    Negation,
    Empty = 1000
};

int sum(const int& a, const int& b) {
    return a + b;
}

long double sum(const long double& a, const long double& b) {
    return a + b;
}

int sub(const int& a, const int& b) {
    return a - b;
}

long double sub(const long double& a, const long double& b) {
    return a - b;
}

int mult(const int& a, const int& b) {
    return a * b;
}

long double mult(const long double& a, const long double& b) {
    return a * b;
}

int division(const int& a, const int& b) {
    return a / b;
}

long double division(const long double& a, const long double& b) {
    return a / b;
}

int mod(const int& a, const int& b) {
    return a % b;
}

int negation(const int& a) {
    if (a == 0) {
        return 1;
    } else {
        return 0;
    }
}

int conjunction(const int& a, const int& b) {
    return (a & b);
}

int disjunction(const int& a, const int& b) {
    return (a | b);
}

int exclusiveOr(const int& a, const int& b) {
    return (a ^ b);
}

int leftShift(const int& a, const int& k) {
    return (a << k);
}

int rightShift(const int& a, const int& k) {
    return (a >> k);
}

int unarySum(const int& a) {
    return (a + 1);
};

int unarySub(const int& a) {
    return (a - 1);
};

operation askForOperation(std::string type) {
    std::string menu;
    if (type == "int") {
        menu = "Sum - 0\nSub - 1\nMult - 2\nDivision - 3\nMod - 4\nConjunction - 5\n";
        menu += "Disjunction - 6\nExclusiveOr - 7\nLeftShift - 8\nRightShift - 9\n";
        menu += "Plus one - 101\nMinus one - 102\nNegation - 103\n";
    } else if (type == "double") {
        menu = "Sum - 0\nSub - 1\nMult - 2\nDivision - 3";
    }

    std::cout << menu;
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

void askForNumber(long double& a) {
    std::cout << "input 1 integer: ";
    std::cin >> a;
}

void askForNumber(long double& a, long double& b) {
    std::cout << "input 2 integer: ";
    std::cin >> a >> b;
}

void applyUnaryOperation(const operation& op, const int& a, int& b) {
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

void applyUnaryOperation(const operation& op, const long double& a, long double& b) {
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

void applyBinaryOperation(const operation& op, const int& a, const int& b, int& c) {
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
            std::cout << "Wrong! Operation is not from the list" << std::endl;
            break;
        }
    }
    return;
}