#pragma once
#define _USE_MATH_DEFINES
#include <string>
#include <math.h>

class Operation {
public:
    bool bin_;
    bool leftAssociative_;
    bool pref_;
    bool isInt_;
    int prior_;
    virtual double operator()(const double& first, const double& second = 0) = 0;
    Operation(bool bin, bool la, bool pr, bool isInt, int prior);
};

double solution(std::string expression);
bool isNumber(const std::string&);
bool isInteger(const std::string&);

class Sum : public Operation{
public:
    Sum(bool bin, bool la, bool pr, bool isInt, int prior);
    double operator()(const double& first, const double& second);
};

class Sub : public Operation {
public:
    Sub(bool bin, bool la, bool pr, bool isInt, int prior);
    double operator()(const double& first, const double& second);
};

class Mult : public Operation {
public:
    Mult(bool bin, bool la, bool pr, bool isInt, int prior);
    double operator()(const double& first, const double& second);
};

class Divide : public Operation {
public:
    Divide(bool bin, bool la, bool pr, bool isInt, int prior);
    double operator()(const double& first, const double& second);
};

class Mod : public Operation {
public:
    Mod(bool bin, bool la, bool pr, bool isInt, int prior);
    double operator()(const double& first, const double& second);
};

class Pow : public Operation {
public:
    Pow(bool bin, bool la, bool pr, bool isInt, int prior);
    double operator()(const double& first, const double& second = 0);
};

class Sqrt : public Operation {
public:
    Sqrt(bool bin, bool la, bool pr, bool isInt, int prior);
    double operator()(const double& first, const double& second = 0);
};

class Fact : public Operation {
public:
    Fact(bool bin, bool la, bool pr, bool isInt, int prior);
    double operator()(const double& first, const double& second = 0);
};

class Sin : public Operation {
public:
    Sin(bool bin, bool la, bool pr, bool isInt, int prior);
    double operator()(const double& first, const double& second = 0);
};

class Cos : public Operation {
public:
    Cos(bool bin, bool la, bool pr, bool isInt, int prior);
    double operator()(const double& first, const double& second = 0);
};

class Tan : public Operation {
public:
    Tan(bool bin, bool la, bool pr, bool isInt, int prior);
    double operator()(const double& first, const double& second = 0);
};

class Ctan : public Operation {
public:
    Ctan(bool bin, bool la, bool pr, bool isInt, int prior);
    double operator()(const double& first, const double& second = 0);
};

class Sec : public Operation {
public:
    Sec(bool bin, bool la, bool pr, bool isInt, int prior);
    double operator()(const double& first, const double& second = 0);
};

class Csc : public Operation {
public:
    Csc(bool bin, bool la, bool pr, bool isInt, int prior);
    double operator()(const double& first, const double& second = 0);
};

class Asin : public Operation {
public:
    Asin(bool bin, bool la, bool pr, bool isInt, int prior);
    double operator()(const double& first, const double& second = 0);
};

class Acos : public Operation {
public:
    Acos(bool bin, bool la, bool pr, bool isInt, int prior);
    double operator()(const double& first, const double& second = 0);
};

class Atan : public Operation {
public:
    Atan(bool bin, bool la, bool pr, bool isInt, int prior);
    double operator()(const double& first, const double& second = 0);
};

class Actan : public Operation {
public:
    Actan(bool bin, bool la, bool pr, bool isInt, int prior);
    double operator()(const double& first, const double& second = 0);
};

class Log : public Operation {
public:
    Log(bool bin, bool la, bool pr, bool isInt, int prior);
    double operator()(const double& first, const double& second = 0);
};

class Ln : public Operation {
public:
    Ln(bool bin, bool la, bool pr, bool isInt, int prior);
    double operator()(const double& first, const double& second = 0);
};

class And : public Operation {
public:
    And(bool bin, bool la, bool pr, bool isInt, int prior);
    double operator()(const double& first, const double& second = 0);
};

class Or : public Operation {
public:
    Or(bool bin, bool la, bool pr, bool isInt, int prior);
    double operator()(const double& first, const double& second = 0);
};

class Xor : public Operation {
public:
    Xor(bool bin, bool la, bool pr, bool isInt, int prior);
    double operator()(const double& first, const double& second = 0);
};

class Not : public Operation {
public:
    Not(bool bin, bool la, bool pr, bool isInt, int prior);
    double operator()(const double& first, const double& second = 0);
};

class Lshift : public Operation {
public:
    Lshift(bool bin, bool la, bool pr, bool isInt, int prior);
    double operator()(const double& first, const double& second = 0);
};

class Rshift : public Operation {
public:
    Rshift(bool bin, bool la, bool pr, bool isInt, int prior);
    double operator()(const double& first, const double& second = 0);
};


