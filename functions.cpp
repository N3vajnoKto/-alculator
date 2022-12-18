#include "functions.h"
#include "stack.h"
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>

Sum sum(true, true, false, false, 6);
Sub sub(true, true, false, false, 6);
Mult mult(true, true, false, false, 5);
Divide divide(true, true, false, false, 5);
Mod mod(true, true, false, true, 5);
Pow mPow(true, false, false, true, 0);
Sqrt mSqrt(true, false, true, false, 0);
Fact fact(false, false, false, true, 0);
Sin mSin(false, false, true, false, 0);
Cos mCos(false, false, true, false, 0);
Tan mTan(false, false, true, false, 0);
Ctan mCtan(false, false, true, false, 0);
Sec sec(false, false, true, false, 0);
Csc csc(false, false, true, false, 0);
Asin mAsin(false, false, true, false, 0);
Acos mAcos(false, false, true, false, 0);
Atan mAtan(false, false, true, false, 0);
Actan mActan(false, false, true, false, 0);
Log mLog(true, false, true, false, 0);
Ln mLn(false, false, true, false, 0);
And mAnd(true, true, false, false, 11);
Or mOr(true, true, false, false, 13);
Xor mXor(true, true, false, false, 12);
Not mNot(false, false, true, false, 3);
Lshift lshift(true, true, false, false, 7);
Rshift rshift(true, true, false, false, 7);


std::map<std::string, Operation*> OP = {
    {"+", &sum},        {"-", &sub},       {"*", &mult},        {"/", &divide},  {"%", &mod},
    {"sin", &mSin},     {"**", &mPow},     {"sqrt", &mSqrt},    {"!", &fact},    {"cos", &mCos},
    {"tg", &mTan},      {"ctg", &mCtan},   {"sec", &sec},       {"csc", &csc},   {"arcsin", &mAsin},
    {"arccos", &mAcos}, {"arctg", &mAtan}, {"arcctg", &mActan}, {"log", &mLog},  {"ln", &mLn},
    {"&", &mAnd},       {"|", &mOr},       {"^", &mXor},        {"<<", &lshift}, {">>", &rshift}, {"~", &mNot} };
std::map<std::string, double> CONST = {{"pi", M_PI}, {"e", M_E}};

Operation::Operation(bool bin, bool la, bool pr, bool isInt, int prior)
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

double solution(std::string expression) {
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
                    || OP.count(element.top()) > 0 && !OP[element.top()]->bin_
                        && !OP[element.top()]->pref_
                    || isNumber(element.top())) {
                    if (elem.empty() && expression[i] == '(' || isNumber(elem)
                        || OP.count(elem) > 0 && OP[elem]->pref_) {
                        while (stack.size() > 0 && stack.top() != "("
                               && (OP[stack.top()]->pref_ || OP[stack.top()]->prior_ < mult.prior_
                                   || OP[stack.top()]->prior_ == mult.prior_
                                       && mult.leftAssociative_)) {
                            pol.push(stack.top());
                            stack.pop();
                        }
                        stack.push("*");
                    }
                }
            }


            if (!elem.empty()) {
                element.push(elem);
                if (OP.count(elem) > 0) {
                    auto operation = OP[elem];
                    if (!operation->pref_ && operation->bin_)
                        while (stack.size() > 0 && stack.top() != "("
                               && (OP[stack.top()]->pref_
                                   || OP[stack.top()]->prior_ < operation->prior_
                                   || OP[stack.top()]->prior_ == operation->prior_
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
                if (isNumber(elem) || OP.count(elem) > 0 && !OP[elem]->bin_ && !OP[elem]->pref_) {
                    while (stack.size() > 0 && stack.top() != "("
                           && (OP[stack.top()]->pref_ || OP[stack.top()]->prior_ < mult.prior_
                               || OP[stack.top()]->prior_ == mult.prior_ && mult.leftAssociative_)
                    ) {
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
                || OP.count(element.top()) > 0 && !OP[element.top()]->bin_
                    && !OP[element.top()]->pref_
                || isNumber(element.top())) {
                if (isNumber(elem) || OP.count(elem) > 0 && OP[elem]->pref_) {
                    while (stack.size() > 0 && stack.top() != "("
                           && (OP[stack.top()]->pref_ || OP[stack.top()]->prior_ < mult.prior_
                               || OP[stack.top()]->prior_ == mult.prior_ && mult.leftAssociative_)
                    ) {
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
        if (OP.count(stack.top()) == 0 && !isNumber(stack.top())) {
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


    StackOnList<double> res;

    while (rev.size() > 0) {
        if (OP.count(rev.top()) > 0) {
            auto operation = OP[rev.top()];
            if (operation->bin_) {
                if (res.size() < 2) {
                    throw std::invalid_argument("cannot do the operation " + rev.top());
                }
                double second = res.top();
                res.pop();
                double first = res.top();
                res.pop();
                res.push((*operation)(first, second));
            } else {
                if (res.size() < 1) {
                    throw std::invalid_argument("cannot do the operation " + rev.top());
                }
                double first = res.top();
                res.pop();
                res.push((*operation)(first));
            }
        } else {
            std::istringstream sin(rev.top());
            double num = 0;
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

Sum::Sum(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation(bin, la, pr, isInt, prior) { }

double Sum::operator()(const double& first, const double& second) {
    return first + second;
}

Sub::Sub(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation(bin, la, pr, isInt, prior) { }

double Sub::operator()(const double& first, const double& second) {
    return first - second;
}

Mult::Mult(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation(bin, la, pr, isInt, prior) { }

double Mult::operator()(const double& first, const double& second) {
    return first * second;
}

Divide::Divide(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation(bin, la, pr, isInt, prior) { }

double Divide::operator()(const double& first, const double& second) {
    if (second == 0) {
        throw std::runtime_error("ERROR! divide by zero.");
    }
    return first / second;
}

Mod::Mod(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation(bin, la, pr, isInt, prior) { }

double Mod::operator()(const double& first, const double& second) {
    long long fint = static_cast<long long>(first);
    long long sint = static_cast<long long>(second);
    if (sint == 0) {
        throw std::runtime_error("ERROR! divide by zero.");
    }
    return static_cast<double>(fint % sint);
}

Pow::Pow(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation(bin, la, pr, isInt, prior) { }

double Pow::operator()(const double& first, const double& second) {
    return pow(first, second);
}

Sqrt::Sqrt(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation(bin, la, pr, isInt, prior) { }

double Sqrt::operator()(const double& first, const double& second) {
    return pow(first, 1.0 / second);
}

Fact::Fact(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation(bin, la, pr, isInt, prior) { }

double Fact::operator()(const double& first, const double& second) {
    double num = static_cast<double>(static_cast<long long>(first + second));
    if (num <= 1)
        return 1.0;
    else
        return num * (*this)(num - 1);
}

Sin::Sin(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation(bin, la, pr, isInt, prior) { }

double Sin::operator()(const double& first, const double& second) {
    return sin(first + second);
}

Cos::Cos(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation(bin, la, pr, isInt, prior) { }

double Cos::operator()(const double& first, const double& second) {
    return cos(first + second);
}

Tan::Tan(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation(bin, la, pr, isInt, prior) { }

double Tan::operator()(const double& first, const double& second) {
    return tan(first + second);
}

Ctan::Ctan(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation(bin, la, pr, isInt, prior) { }

double Ctan::operator()(const double& first, const double& second) {
    if (tan(first + second) == 0) {
        throw std::invalid_argument(
            "cannot do the operation: ctg(" + std::to_string(first) + ") does not exsist."
        );
    }
    return 1.0 / tan(first + second);
}

Sec::Sec(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation(bin, la, pr, isInt, prior) { }

double Sec::operator()(const double& first, const double& second) {
    return 1.0 / cos(first + second);
}

Csc::Csc(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation(bin, la, pr, isInt, prior) { }

double Csc::operator()(const double& first, const double& second) {
    return 1.0 / sin(first + second);
}

Asin::Asin(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation(bin, la, pr, isInt, prior) { }

double Asin::operator()(const double& first, const double& second) {
    return asin(first + second);
}

Acos::Acos(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation(bin, la, pr, isInt, prior) { }

double Acos::operator()(const double& first, const double& second) {
    return acos(first + second);
}

Atan::Atan(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation(bin, la, pr, isInt, prior) { }

double Atan::operator()(const double& first, const double& second) {
    return atan(first + second);
}

Actan::Actan(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation(bin, la, pr, isInt, prior) { }

double Actan::operator()(const double& first, const double& second) {
    return M_PI_2 - atan(first + second);
}

Log::Log(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation(bin, la, pr, isInt, prior) { }

double Log::operator()(const double& first, const double& second) {
    if (first <= 0 || second <= 0) {
        throw std::invalid_argument(
            "cannot do the operation log: base " + std::to_string(first) + "("
            + std::to_string(second) + " does not exsist."
        );
    }

    return log(second) / log(first);
}

Ln::Ln(bool bin, bool la, bool pr, bool isInt, int prior) : Operation(bin, la, pr, isInt, prior) { }

double Ln::operator()(const double& first, const double& second) {
    if (first <= 0) {
        throw std::invalid_argument(
            "cannot do the operation ln: ln(" + std::to_string(first) + ") does not exsist."
        );
    }
    return log(first + second);
}

And::And(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation(bin, la, pr, isInt, prior) { }

double And::operator()(const double& first, const double& second) {
    long long lfirst = static_cast<long long>(first);
    long long lsecond = static_cast<long long>(second);
    return static_cast<double>(lfirst & lsecond);
}

Or::Or(bool bin, bool la, bool pr, bool isInt, int prior) : Operation(bin, la, pr, isInt, prior) { }

double Or::operator()(const double& first, const double& second) {
    long long lfirst = static_cast<long long>(first);
    long long lsecond = static_cast<long long>(second);
    return static_cast<double>(lfirst | lsecond);
}

Not::Not(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation(bin, la, pr, isInt, prior) { }

double Not::operator()(const double& first, const double& second) {
    long long lfirst = static_cast<long long>(first+second);
    return static_cast<double>(~lfirst);
}

Xor::Xor(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation(bin, la, pr, isInt, prior) { }

double Xor::operator()(const double& first, const double& second) {
    long long lfirst = static_cast<long long>(first);
    long long lsecond = static_cast<long long>(second);
    return static_cast<double>(lfirst ^ lsecond);
}

Lshift::Lshift(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation(bin, la, pr, isInt, prior) { }

double Lshift::operator()(const double& first, const double& second) {
    long long lfirst = static_cast<long long>(first);
    long long lsecond = static_cast<long long>(second);
    return static_cast<double>(lfirst << lsecond);
}

Rshift::Rshift(bool bin, bool la, bool pr, bool isInt, int prior)
    : Operation(bin, la, pr, isInt, prior) { }

double Rshift::operator()(const double& first, const double& second) {
    long long lfirst = static_cast<long long>(first);
    long long lsecond = static_cast<long long>(second);
    return static_cast<double>(lfirst >> lsecond);
}
