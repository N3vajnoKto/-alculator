#pragma once
#define _USE_MATH_DEFINES
#include "stack.h"
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <sstream>
#include <string>
#include <vector>

template<typename T>
class Operation {
public:
    bool bin_;
    bool leftAssociative_;
    bool pref_;
    bool isInt_;
    int prior_;
    virtual T operator()(const T& first, const T& second = 0) = 0;
    Operation(bool bin, bool la, bool pr, bool isInt, int prior);
};

template<typename T>
class Sum : public Operation<T> {
public:
    Sum(bool bin, bool la, bool pr, bool isInt, int prior);
    T operator()(const T& first, const T& second);
};

template<typename T>
class Sub : public Operation<T> {
public:
    Sub(bool bin, bool la, bool pr, bool isInt, int prior);
    T operator()(const T& first, const T& second);
};

template<typename T>
class Mult : public Operation<T> {
public:
    Mult(bool bin, bool la, bool pr, bool isInt, int prior);
    T operator()(const T& first, const T& second);
};

template<typename T>
class Divide : public Operation<T> {
public:
    Divide(bool bin, bool la, bool pr, bool isInt, int prior);
    T operator()(const T& first, const T& second);
};

template<typename T>
class Mod : public Operation<T> {
public:
    Mod(bool bin, bool la, bool pr, bool isInt, int prior);
    T operator()(const T& first, const T& second);
};

template<typename T>
class Pow : public Operation<T> {
public:
    Pow(bool bin, bool la, bool pr, bool isInt, int prior);
    T operator()(const T& first, const T& second = 0);
};

template<typename T>
class Sqrt : public Operation<T> {
public:
    Sqrt(bool bin, bool la, bool pr, bool isInt, int prior);
    T operator()(const T& first, const T& second = 0);
};

template<typename T>
class Fact : public Operation<T> {
public:
    Fact(bool bin, bool la, bool pr, bool isInt, int prior);
    T operator()(const T& first, const T& second = 0);
};

template<typename T>
class Sin : public Operation<T> {
public:
    Sin(bool bin, bool la, bool pr, bool isInt, int prior);
    T operator()(const T& first, const T& second = 0);
};

template<typename T>
class Cos : public Operation<T> {
public:
    Cos(bool bin, bool la, bool pr, bool isInt, int prior);
    T operator()(const T& first, const T& second = 0);
};

template<typename T>
class Tan : public Operation<T> {
public:
    Tan(bool bin, bool la, bool pr, bool isInt, int prior);
    T operator()(const T& first, const T& second = 0);
};

template<typename T>
class Ctan : public Operation<T> {
public:
    Ctan(bool bin, bool la, bool pr, bool isInt, int prior);
    T operator()(const T& first, const T& second = 0);
};

template<typename T>
class Sec : public Operation<T> {
public:
    Sec(bool bin, bool la, bool pr, bool isInt, int prior);
    T operator()(const T& first, const T& second = 0);
};

template<typename T>
class Csc : public Operation<T> {
public:
    Csc(bool bin, bool la, bool pr, bool isInt, int prior);
    T operator()(const T& first, const T& second = 0);
};

template<typename T>
class Asin : public Operation<T> {
public:
    Asin(bool bin, bool la, bool pr, bool isInt, int prior);
    T operator()(const T& first, const T& second = 0);
};

template<typename T>
class Acos : public Operation<T> {
public:
    Acos(bool bin, bool la, bool pr, bool isInt, int prior);
    T operator()(const T& first, const T& second = 0);
};

template<typename T>
class Atan : public Operation<T> {
public:
    Atan(bool bin, bool la, bool pr, bool isInt, int prior);
    T operator()(const T& first, const T& second = 0);
};

template<typename T>
class Actan : public Operation<T> {
public:
    Actan(bool bin, bool la, bool pr, bool isInt, int prior);
    T operator()(const T& first, const T& second = 0);
};

template<typename T>
class Log : public Operation<T> {
public:
    Log(bool bin, bool la, bool pr, bool isInt, int prior);
    T operator()(const T& first, const T& second = 0);
};

template<typename T>
class Ln : public Operation<T> {
public:
    Ln(bool bin, bool la, bool pr, bool isInt, int prior);
    T operator()(const T& first, const T& second = 0);
};

template<typename T>
class And : public Operation<T> {
public:
    And(bool bin, bool la, bool pr, bool isInt, int prior);
    T operator()(const T& first, const T& second = 0);
};

template<typename T>
class Or : public Operation<T> {
public:
    Or(bool bin, bool la, bool pr, bool isInt, int prior);
    T operator()(const T& first, const T& second = 0);
};

template<typename T>
class Xor : public Operation<T> {
public:
    Xor(bool bin, bool la, bool pr, bool isInt, int prior);
    T operator()(const T& first, const T& second = 0);
};

template<typename T>
class Not : public Operation<T> {
public:
    Not(bool bin, bool la, bool pr, bool isInt, int prior);
    T operator()(const T& first, const T& second = 0);
};

template<typename T>
class Lshift : public Operation<T> {
public:
    Lshift(bool bin, bool la, bool pr, bool isInt, int prior);
    T operator()(const T& first, const T& second = 0);
};

template<typename T>
class Rshift : public Operation<T> {
public:
    Rshift(bool bin, bool la, bool pr, bool isInt, int prior);
    T operator()(const T& first, const T& second = 0);
};

template<typename T>
Operation<T>::Operation(bool bin, bool la, bool pr, bool isInt, int prior)
    : bin_(bin), leftAssociative_(la), pref_(pr), isInt_(isInt), prior_(prior) { }

bool isNumber(const std::string& expression) {
    int num = 0;
    bool ok = 1;
    for (char digit : expression) {
        num += static_cast<int>(digit == '.');
        ok &= (digit >= '0' && digit <= '9' || digit == '.');
    }
    ok &= (num < 2);
    ok &= (expression.size() > 0);
    return ok;
}

bool isInteger(const std::string& expression) {
    int num = 0;
    bool ok = 1;
    for (char digit : expression) {
        num += static_cast<int>(digit == '.');
        ok &= (digit >= '0' && digit <= '9' || digit == '.');
    }
    ok &= (num == 0);
    ok &= (expression.size() > 0);
    return ok;
}

template<typename T>
class Operations {
public:
    Sum<T> sum = Sum<T>(true, true, false, false, 6);
    Sub<T> sub = Sub<T>(true, true, false, false, 6);
    Mult<T> mult = Mult<T>(true, true, false, false, 5);
    Divide<T> divide = Divide<T>(true, true, false, false, 5);
    Mod<T> mod = Mod<T>(true, true, false, true, 5);
    Pow<T> mPow = Pow<T>(true, false, false, true, 0);
    Sqrt<T> mSqrt = Sqrt<T>(true, false, true, false, 0);
    Fact<T> fact = Fact<T>(false, false, false, true, 0);
    Sin<T> mSin = Sin<T>(false, false, true, false, 0);
    Cos<T> mCos = Cos<T>(false, false, true, false, 0);
    Tan<T> mTan = Tan<T>(false, false, true, false, 0);
    Ctan<T> mCtan = Ctan<T>(false, false, true, false, 0);
    Sec<T> sec = Sec<T>(false, false, true, false, 0);
    Csc<T> csc = Csc<T>(false, false, true, false, 0);
    Asin<T> mAsin = Asin<T>(false, false, true, false, 0);
    Acos<T> mAcos = Acos<T>(false, false, true, false, 0);
    Atan<T> mAtan = Atan<T>(false, false, true, false, 0);
    Actan<T> mActan = Actan<T>(false, false, true, false, 0);
    Log<T> mLog = Log<T>(true, false, true, false, 0);
    Ln<T> mLn = Ln<T>(false, false, true, false, 0);
    And<T> mAnd = And<T>(true, true, false, false, 11);
    Or<T> mOr = Or<T>(true, true, false, false, 13);
    Xor<T> mXor = Xor<T>(true, true, false, false, 12);
    Not<T> mNot = Not<T>(false, false, true, false, 3);
    Lshift<T> lshift = Lshift<T>(true, true, false, false, 7);
    Rshift<T> rshift = Rshift<T>(true, true, false, false, 7);

    std::map<std::string, Operation<T>*> data = {
        {"+", &sum},       {"-", &sub},         {"*", &mult},       {"/", &divide},
        {"%", &mod},       {"sin", &mSin},      {"**", &mPow},      {"sqrt", &mSqrt},
        {"!", &fact},      {"cos", &mCos},      {"tg", &mTan},      {"ctg", &mCtan},
        {"sec", &sec},     {"csc", &csc},       {"arcsin", &mAsin}, {"arccos", &mAcos},
        {"arctg", &mAtan}, {"arcctg", &mActan}, {"log", &mLog},     {"ln", &mLn},
        {"&", &mAnd},      {"|", &mOr},         {"^", &mXor},       {"<<", &lshift},
        {">>", &rshift},   {"~", &mNot}};
};

template<>
class Operations<double> {
public:
    Sum<double> sum = Sum<double>(true, true, false, false, 6);
    Sub<double> sub = Sub<double>(true, true, false, false, 6);
    Mult<double> mult = Mult<double>(true, true, false, false, 5);
    Divide<double> divide = Divide<double>(true, true, false, false, 5);
    Pow<double> mPow = Pow<double>(true, false, false, true, 0);
    Sqrt<double> mSqrt = Sqrt<double>(true, false, true, false, 0);
    Sin<double> mSin = Sin<double>(false, false, true, false, 0);
    Cos<double> mCos = Cos<double>(false, false, true, false, 0);
    Tan<double> mTan = Tan<double>(false, false, true, false, 0);
    Ctan<double> mCtan = Ctan<double>(false, false, true, false, 0);
    Sec<double> sec = Sec<double>(false, false, true, false, 0);
    Csc<double> csc = Csc<double>(false, false, true, false, 0);
    Asin<double> mAsin = Asin<double>(false, false, true, false, 0);
    Acos<double> mAcos = Acos<double>(false, false, true, false, 0);
    Atan<double> mAtan = Atan<double>(false, false, true, false, 0);
    Actan<double> mActan = Actan<double>(false, false, true, false, 0);
    Log<double> mLog = Log<double>(true, false, true, false, 0);
    Ln<double> mLn = Ln<double>(false, false, true, false, 0);

    std::map<std::string, Operation<double>*> data = {
        {"+", &sum},        {"-", &sub},        {"*", &mult},      {"/", &divide},
        {"sin", &mSin},     {"**", &mPow},      {"sqrt", &mSqrt},  {"cos", &mCos},
        {"tg", &mTan},      {"ctg", &mCtan},    {"sec", &sec},     {"csc", &csc},
        {"arcsin", &mAsin}, {"arccos", &mAcos}, {"arctg", &mAtan}, {"arcctg", &mActan},
        {"log", &mLog},     {"ln", &mLn}};
};

template<>
class Operations<long long> {
public:
    Sum<long long> sum = Sum<long long>(true, true, false, false, 6);
    Sub<long long> sub = Sub<long long>(true, true, false, false, 6);
    Mult<long long> mult = Mult<long long>(true, true, false, false, 5);
    Divide<long long> divide = Divide<long long>(true, true, false, false, 5);
    Mod<long long> mod = Mod<long long>(true, true, false, true, 5);
    Pow<long long> mPow = Pow<long long>(true, false, false, true, 0);
    Sqrt<long long> mSqrt = Sqrt<long long>(true, false, true, false, 0);
    Fact<long long> fact = Fact<long long>(false, false, false, true, 0);
    And<long long> mAnd = And<long long>(true, true, false, false, 11);
    Or<long long> mOr = Or<long long>(true, true, false, false, 13);
    Xor<long long> mXor = Xor<long long>(true, true, false, false, 12);
    Not<long long> mNot = Not<long long>(false, false, true, false, 3);
    Lshift<long long> lshift = Lshift<long long>(true, true, false, false, 7);
    Rshift<long long> rshift = Rshift<long long>(true, true, false, false, 7);

    std::map<std::string, Operation<long long>*> data = {
        {"+", &sum},   {"-", &sub},      {"*", &mult},    {"/", &divide}, {"%", &mod},
        {"**", &mPow}, {"sqrt", &mSqrt}, {"!", &fact},    {"&", &mAnd},   {"|", &mOr},
        {"^", &mXor},  {"<<", &lshift},  {">>", &rshift}, {"~", &mNot}};
};

template<typename T>
T solution(std::string expression) {

    Operations<T> OP;

    std::map<std::string, double> CONST = {{"pi", M_PI}, {"e", M_E}};
    std::set<char> del = {'(', ')', ' ', ','};

    std::string elem;
    StackOnList<std::string> pol;
    StackOnList<std::string> stack;
    StackOnList<std::string> element;

    bool number = 1;

    for (int i = 0; i < static_cast<int>(expression.size()); ++i) {
        if (del.count(expression[i]) == 0
            && number == ('0' <= expression[i] && expression[i] <= '9' || expression[i] == '.')) {
            elem += expression[i];
        } else {
            if (CONST.count(elem) > 0) {
                elem = std::to_string(CONST[elem]);
            }
            if (element.size() > 0) {
                if (element.top() == ")"
                    || OP.data.count(element.top()) > 0 && !OP.data[element.top()]->bin_
                        && !OP.data[element.top()]->pref_
                    || isNumber(element.top())) {
                    if (elem.empty() && expression[i] == '(' || isNumber(elem)
                        || OP.data.count(elem) > 0 && OP.data[elem]->pref_) {
                        while (stack.size() > 0 && stack.top() != "("
                               && (OP.data[stack.top()]->pref_
                                   || OP.data[stack.top()]->prior_ < OP.mult.prior_
                                   || OP.data[stack.top()]->prior_ == OP.mult.prior_
                                       && OP.mult.leftAssociative_)) {
                            pol.push(stack.top());
                            stack.pop();
                        }
                        stack.push("*");
                    }
                }
            }


            if (!elem.empty()) {
                element.push(elem);
                if (OP.data.count(elem) > 0) {
                    auto operation = OP.data[elem];
                    if (!operation->pref_ && operation->bin_)
                        while (stack.size() > 0 && stack.top() != "("
                               && (OP.data[stack.top()]->pref_
                                   || OP.data[stack.top()]->prior_ < operation->prior_
                                   || OP.data[stack.top()]->prior_ == operation->prior_
                                       && operation->leftAssociative_)) {
                            pol.push(stack.top());
                            stack.pop();
                        }
                    stack.push(elem);
                } else {
                    if (!isNumber(elem)) {
                        throw std::invalid_argument("cannot understand " + elem);
                    }
                    pol.push(elem);
                }
            }
            if (expression[i] == ')') {
                element.push(")");
                while (stack.size() > 0 && stack.top() != "(") {
                    pol.push(stack.top());
                    stack.pop();
                }
                if (stack.size() == 0) {
                    throw std::invalid_argument("bad expression");
                }
                stack.pop();
            }

            if (expression[i] == '(') {
                element.push("(");
                if (isNumber(elem)
                    || OP.data.count(elem) > 0 && !OP.data[elem]->bin_ && !OP.data[elem]->pref_) {
                    while (stack.size() > 0 && stack.top() != "("
                           && (OP.data[stack.top()]->pref_
                               || OP.data[stack.top()]->prior_ < OP.mult.prior_
                               || OP.data[stack.top()]->prior_ == OP.mult.prior_
                                   && OP.mult.leftAssociative_)) {
                        pol.push(stack.top());
                        stack.pop();
                    }
                    stack.push("*");
                }
                stack.push("(");
            }

            if (expression[i] == ',') {
                element.push(",");
                while (stack.size() && stack.top() != "(") {
                    pol.push(stack.top());
                    stack.pop();
                }
                if (stack.size() == 0) {
                    throw std::invalid_argument("ERROR! wrong arguments");
                }
            }

            elem = "";
            if (del.count(expression[i]) == 0) {
                elem += expression[i];
                if ('0' <= expression[i] && expression[i] <= '9') {
                    number = 1;
                } else {
                    number = 0;
                }
            }
        }
    }


    if (!elem.empty()) {
        if (CONST.count(elem) > 0) {
            elem = std::to_string(CONST[elem]);
        }
        if (element.size() > 0) {
            if (element.top() == ")"
                || OP.data.count(element.top()) > 0 && !OP.data[element.top()]->bin_
                    && !OP.data[element.top()]->pref_
                || isNumber(element.top())) {
                if (isNumber(elem) || OP.data.count(elem) > 0 && OP.data[elem]->pref_) {
                    while (stack.size() > 0 && stack.top() != "("
                           && (OP.data[stack.top()]->pref_
                               || OP.data[stack.top()]->prior_ < OP.mult.prior_
                               || OP.data[stack.top()]->prior_ == OP.mult.prior_
                                   && OP.mult.leftAssociative_)) {
                        pol.push(stack.top());
                        stack.pop();
                    }
                    stack.push("*");
                }
            }
        }
        pol.push(elem);
    }

    while (stack.size() > 0) {
        if (OP.data.count(stack.top()) == 0 && !isNumber(stack.top())) {
            throw std::invalid_argument("bad expression");
        }
        pol.push(stack.top());
        stack.pop();
    }

    StackOnList<std::string> rev;
    while (pol.size() > 0) {
        rev.push(pol.top());
        pol.pop();
    }


    StackOnList<T> res;

    while (rev.size() > 0) {
        if (OP.data.count(rev.top()) > 0) {
            auto operation = OP.data[rev.top()];
            if (operation->bin_) {
                if (res.size() < 2) {
                    throw std::invalid_argument("cannot do the operation " + rev.top());
                }
                T second = res.top();
                res.pop();
                T first = res.top();
                res.pop();
                res.push((*operation)(first, second));
            } else {
                if (res.size() < 1) {
                    throw std::invalid_argument("cannot do the operation " + rev.top());
                }
                T first = res.top();
                res.pop();
                res.push((*operation)(first));
            }
        } else {
            std::istringstream sin(rev.top());
            T num = 0;
            sin >> num;
            res.push(num);
        }
        rev.pop();
    }
    if (res.size() != 1) {
        throw std::invalid_argument("Bad experssion");
    }

    return res.top();
}

template<typename T>
Sum<T>::Sum(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation<T>(bin, la, pr, isInt, prior) { }

template<typename T>
T Sum<T>::operator()(const T& first, const T& second) {
    return first + second;
}

template<typename T>
Sub<T>::Sub(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation<T>(bin, la, pr, isInt, prior) { }

template<typename T>
T Sub<T>::operator()(const T& first, const T& second) {
    return first - second;
}

template<typename T>
Mult<T>::Mult(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation<T>(bin, la, pr, isInt, prior) { }

template<typename T>
T Mult<T>::operator()(const T& first, const T& second) {
    return first * second;
}

template<typename T>
Divide<T>::Divide(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation<T>(bin, la, pr, isInt, prior) { }

template<typename T>
T Divide<T>::operator()(const T& first, const T& second) {
    if (second == 0) {
        throw std::runtime_error("ERROR! divide by zero.");
    }
    return first / second;
}

template<typename T>
Mod<T>::Mod(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation<T>(bin, la, pr, isInt, prior) { }

template<typename T>
T Mod<T>::operator()(const T& first, const T& second) {
    long long fint = static_cast<long long>(first);
    long long sint = static_cast<long long>(second);
    if (sint == 0) {
        throw std::runtime_error("ERROR! divide by zero.");
    }
    return static_cast<T>(fint % sint);
}

template<typename T>
Pow<T>::Pow(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation(bin, la, pr, isInt, prior) { }

template<typename T>
T Pow<T>::operator()(const T& first, const T& second) {
    return pow(first, second);
}

template<>
long long Pow<long long>::operator()(const long long& first, const long long& second) {
    if (second < 0) {
        throw std::invalid_argument("degree below 0");
    }
    long long res = 1;
    long long st = second;
    long long num = first;
    while (st) {
        if (st % 2) {
            res *= num;
        }
        num *= num;
        st /= 2;
    }

    return res;
}

template<typename T>
Sqrt<T>::Sqrt(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation(bin, la, pr, isInt, prior) { }

template<typename T>
T Sqrt<T>::operator()(const T& first, const T& second) {
    return static_cast<T>(pow(first, 1.0 / second));
}

template<typename T>
Fact<T>::Fact(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation<T>(bin, la, pr, isInt, prior) { }

template<typename T>
T Fact<T>::operator()(const T& first, const T& second) {
    T num = static_cast<T>(static_cast<long long>(first + second));
    if (num <= 1)
        return 1;
    else
        return num * (*this)(num - 1);
}

template<typename T>
Sin<T>::Sin(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation<T>(bin, la, pr, isInt, prior) { }

template<typename T>
T Sin<T>::operator()(const T& first, const T& second) {
    return sin(first + second);
}

template<typename T>
Cos<T>::Cos(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation<T>(bin, la, pr, isInt, prior) { }

template<typename T>
T Cos<T>::operator()(const T& first, const T& second) {
    return cos(first + second);
}

template<typename T>
Tan<T>::Tan(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation<T>(bin, la, pr, isInt, prior) { }

template<typename T>
T Tan<T>::operator()(const T& first, const T& second) {
    return tan(first + second);
}

template<typename T>
Ctan<T>::Ctan(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation<T>(bin, la, pr, isInt, prior) { }

template<typename T>
T Ctan<T>::operator()(const T& first, const T& second) {
    if (tan(first + second) == 0) {
        throw std::invalid_argument(
            "cannot do the operation: ctg(" + std::to_string(first) + ") does not exsist."
        );
    }
    return 1.0 / tan(first + second);
}

template<typename T>
Sec<T>::Sec(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation<T>(bin, la, pr, isInt, prior) { }

template<typename T>
T Sec<T>::operator()(const T& first, const T& second) {
    return 1.0 / cos(first + second);
}

template<typename T>
Csc<T>::Csc(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation<T>(bin, la, pr, isInt, prior) { }

template<typename T>
T Csc<T>::operator()(const T& first, const T& second) {
    return 1.0 / sin(first + second);
}

template<typename T>
Asin<T>::Asin(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation<T>(bin, la, pr, isInt, prior) { }

template<typename T>
T Asin<T>::operator()(const T& first, const T& second) {
    return asin(first + second);
}

template<typename T>
Acos<T>::Acos(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation<T>(bin, la, pr, isInt, prior) { }

template<typename T>
T Acos<T>::operator()(const T& first, const T& second) {
    return acos(first + second);
}

template<typename T>
Atan<T>::Atan(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation<T>(bin, la, pr, isInt, prior) { }

template<typename T>
T Atan<T>::operator()(const T& first, const T& second) {
    return atan(first + second);
}

template<typename T>
Actan<T>::Actan(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation<T>(bin, la, pr, isInt, prior) { }

template<typename T>
T Actan<T>::operator()(const T& first, const T& second) {
    return M_PI_2 - atan(first + second);
}

template<typename T>
Log<T>::Log(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation<T>(bin, la, pr, isInt, prior) { }

template<typename T>
T Log<T>::operator()(const T& first, const T& second) {
    if (first <= 0 || second <= 0) {
        throw std::invalid_argument(
            "cannot do the operation log: base " + std::to_string(first) + "("
            + std::to_string(second) + " does not exsist."
        );
    }

    return log(second) / log(first);
}

template<typename T>
Ln<T>::Ln(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation<T>(bin, la, pr, isInt, prior) { }

template<typename T>
T Ln<T>::operator()(const T& first, const T& second) {
    if (first <= 0) {
        throw std::invalid_argument(
            "cannot do the operation ln: ln(" + std::to_string(first) + ") does not exsist."
        );
    }
    return log(first + second);
}

template<typename T>
And<T>::And(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation<T>(bin, la, pr, isInt, prior) { }

template<typename T>
T And<T>::operator()(const T& first, const T& second) {
    long long lfirst = static_cast<long long>(first);
    long long lsecond = static_cast<long long>(second);
    return static_cast<T>(lfirst & lsecond);
}

template<typename T>
Or<T>::Or(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation<T>(bin, la, pr, isInt, prior) { }

template<typename T>
T Or<T>::operator()(const T& first, const T& second) {
    long long lfirst = static_cast<long long>(first);
    long long lsecond = static_cast<long long>(second);
    return static_cast<T>(lfirst | lsecond);
}

template<typename T>
Not<T>::Not(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation<T>(bin, la, pr, isInt, prior) { }

template<typename T>
T Not<T>::operator()(const T& first, const T& second) {
    long long lfirst = static_cast<long long>(first + second);
    return static_cast<T>(~lfirst);
}

template<typename T>
Xor<T>::Xor(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation<T>(bin, la, pr, isInt, prior) { }

template<typename T>
T Xor<T>::operator()(const T& first, const T& second) {
    long long lfirst = static_cast<long long>(first);
    long long lsecond = static_cast<long long>(second);
    return static_cast<T>(lfirst ^ lsecond);
}

template<typename T>
Lshift<T>::Lshift(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation<T>(bin, la, pr, isInt, prior) { }

template<typename T>
T Lshift<T>::operator()(const T& first, const T& second) {
    long long lfirst = static_cast<long long>(first);
    long long lsecond = static_cast<long long>(second);
    return static_cast<T>(lfirst << lsecond);
}

template<typename T>
Rshift<T>::Rshift(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation<T>(bin, la, pr, isInt, prior) { }

template<typename T>
T Rshift<T>::operator()(const T& first, const T& second) {
    long long lfirst = static_cast<long long>(first);
    long long lsecond = static_cast<long long>(second);
    return static_cast<T>(lfirst >> lsecond);
}
