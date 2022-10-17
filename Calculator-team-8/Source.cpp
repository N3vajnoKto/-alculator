#include <iostream>

int sum(const int&, const int&);
int sub(const int&, const int&);
int mult(const int&, const int&);
int division(const int&, const int&);
int mod(const int&, const int&);
int negation(const int&);
int conjunction(const int&, const int&);
int disjunction(const int&, const int&);
int exclusiveOr(const int&, const int&);
int leftshift(const int&, const int&);
int rightshift(const int&, const int&);

long double sum(const long double&, const long double&);
long double sub(const long double&, const long double&);
long double mult(const long double&, const long double&);
long double division(const long double&, const long double&);

<<<<<<< HEAD
enum operation {
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
    UnPlus,
    UnMinus,
    Negation,
    Empty = 1000
};
=======
enum operation { Sum, Sub, Mult, Division, Mod, Exp = 100, Empty = 1000, unplus = 101, unminus = 102 };
>>>>>>> a1042f45e44df06e9b72d9df29fb436735ef6543

bool isUnary(operation&);
void askForNumber(int&);
void askForNumber(int&, int&);
void askForNumber(long double&);
void askForNumber(long double&, long double&);

void applyUnaryOperation(const operation&, const int&, int&);
void applyUnaryOperation(const operation&, const long double&, long double&);
void applyBinaryOperation(const operation&, const int&, const int&, int&);
void applyBinaryOperation(const operation&, const long double&, const long double&, long double&);

operation askForOperation(std::string);

int main() {
    while (true) {
        std::string varType;
        std::cout << "Which type?" << std::endl;

        std::cin >> varType;

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
        } else {
            std::cout << "Wrong type!" << std::endl;
        }
    }
}

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

<<<<<<< HEAD
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

operation askForOperation(std::string type) {
    std::string menu;
    if (type == "int") {
        menu = "Sum - 0\nSub - 1\nMult - 2\nDivision - 3\nMod - 4\nConjunction - 5\n";
        menu += "Disjunction - 6\nExclusiveOr - 7\nLeftShift - 8\nRightShift - 9\n";
        menu += "Plus one - 101\nMinus one - 102\nNegation - 103\n";
    } else if (type == "double") {
        menu = "Sum - 0\nSub - 1\nMult - 2\nDivision - 3";
    }
=======
operation askForOperation() {
    std::string menu = "Sum - 0\nSub - 1\nMult - 2\nDivision - 3\nMod - 4\nplus one - 101\nminus one - 102\n";
>>>>>>> a1042f45e44df06e9b72d9df29fb436735ef6543
    std::cout << menu;
    std::cout << "operation? ";
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
<<<<<<< HEAD
        case UnPlus: {
            b = a + 1;
            break;
        }
        case UnMinus: {
            b = a - 1;
            break;
        }
        case (Negation): {
            b = negation(a);
            break;
        }
=======
        case unplus: {
            b = a + 1;
            break;
        }
        case unminus: {
            b = a - 1;
            break;
        }
>>>>>>> a1042f45e44df06e9b72d9df29fb436735ef6543
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

void applyBinaryOperation(
    const operation& op, const int& a, const int& b, int& c
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