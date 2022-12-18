#pragma once
#include <string>

class Operation {
public:
    bool bin_;
    bool leftAssociative_;
    bool pref_;
    int prior_;
    virtual double operator()(const double& first, const double& second = 0) = 0;
    Operation(bool bin, bool la, bool pr, int prior);
};

double solution(std::string expression);
bool isNumber(const std::string&);

class Sum : public Operation{
public:
    Sum(bool bin, bool la, bool pr, int prior);
    double operator()(const double& first, const double& second);
};

class Sub : public Operation {
public:
    Sub(bool bin, bool la, bool pr, int prior);
    double operator()(const double& first, const double& second);
};

class Mult : public Operation {
public:
    Mult(bool bin, bool la, bool pr, int prior);
    double operator()(const double& first, const double& second);
};

class Divide : public Operation {
public:
    Divide(bool bin, bool la, bool pr, int prior);
    double operator()(const double& first, const double& second);
};