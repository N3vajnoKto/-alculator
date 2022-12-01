#pragma once
#include <iostream>
#include <string>

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

int sum(int a, int b);

double sum(double a, double b);

int sub(const int a, const int b);

double sub(const double a, const double b);

int mult(const int a, const int b);

double mult(const double a, const double b);

int division(const int a, const int b);

double division(const double a, const double b);

int mod(const int a, const int b);

int negation(const int a);

int conjunction(const int a, const int b);

int disjunction(const int a, const int b);

int exclusiveOr(const int a, const int b);

int leftShift(const int a, const int k);

int rightShift(const int a, const int k);

int unarySum(const int a);

int unarySub(const int a);

bool isUnary(operation&);
void askForNumber(int&);
void askForNumber(int&, int&);
void askForNumber(double&);
void askForNumber(double&, double&);

void applyUnaryOperation(const operation&, const int, int&);
void applyUnaryOperation(const operation&, const double, double&);
void applyBinaryOperation(const operation&, const int, const int, int&);
void applyBinaryOperation(const operation&, const double, const double, double&);

operation askForOperation(std::string);
