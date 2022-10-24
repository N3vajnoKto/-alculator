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
