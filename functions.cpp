#include "functions.h"
#include "stack.h"
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>

Sum sum(true, true, false, 6);
Sub sub(true, true, false, 6);
Mult mult(true, true, false, 5);
Divide divide(true, true, false, 5);

std::map<std::string, Operation*> OP = {{"+", &sum}, {"-", &sub}, {"*", &mult}, {"/", &divide}};

Operation::Operation(bool bin, bool la, bool pr, int prior)
    : bin_(bin), leftAssociative_(la), pref_(pr), prior_(prior) { }

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
            if (element.size() > 0) {
                if (element.top() == ")"
                    || OP.count(element.top()) > 0 && !OP[element.top()]->bin_
                        && !OP[element.top()]->pref_
                    || isNumber(element.top())) {
                    if (elem.empty() && expression[i] == '(' || isNumber(elem)
                        || OP.count(elem) > 0 && OP[elem]->pref_) {
                        while (stack.size() > 0 && stack.top() != "("
                               && (OP[stack.top()]->pref_ || OP[stack.top()]->prior_ <= mult.prior_
                                   || OP[stack.top()]->prior_ <= mult.prior_
                                       && OP[stack.top()]->leftAssociative_)) {
                            pol.push(stack.top());
                            stack.pop();
                        }
                        stack.push("*");
                    }
                }
            }


            if (!elem.empty()) {
                element.push(elem);
                if (OP.count(elem) > 0 && OP[elem]->bin_) {
                    auto operation = OP[elem];
                    if (!operation->pref_)
                        while (stack.size() > 0 && stack.top() != "("
                               && (OP[stack.top()]->pref_
                                   || OP[stack.top()]->prior_ <= operation->prior_
                                   || OP[stack.top()]->prior_ <= operation->prior_
                                       && OP[stack.top()]->leftAssociative_)) {
                            pol.push(stack.top());
                            stack.pop();
                        }
                    stack.push(elem);
                } else {
                    if (OP.count(elem) == 0 && !isNumber(elem)) {
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
                    || OP.count(elem) > 0 && !OP[elem]->bin_
                        && !OP[elem]->pref_) {
                    while (stack.size() > 0 && stack.top() != "("
                           && (OP[stack.top()]->pref_ || OP[stack.top()]->prior_ <= mult.prior_
                               || OP[stack.top()]->prior_ <= mult.prior_
                                   && OP[stack.top()]->leftAssociative_)) {
                        pol.push(stack.top());
                        stack.pop();
                    }
                    stack.push("*");
                }
                stack.push("(");
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
        if (OP.count(elem) == 0) {
            if (!isNumber(elem)) {
                throw std::invalid_argument("cannot understand " + elem);
            }
            if (element.size() > 0) {
                if (element.top() == ")"
                    || OP.count(element.top()) > 0 && !OP[element.top()]->bin_
                    && !OP[element.top()]->pref_
                    || isNumber(element.top())) {
                    if (isNumber(elem)
                        || OP.count(elem) > 0 && OP[elem]->pref_) {
                        while (stack.size() > 0 && stack.top() != "("
                            && (OP[stack.top()]->pref_ || OP[stack.top()]->prior_ <= mult.prior_
                                || OP[stack.top()]->prior_ <= mult.prior_
                                && OP[stack.top()]->leftAssociative_)) {
                            pol.push(stack.top());
                            stack.pop();
                        }
                        stack.push("*");
                    }
                }
            }
            pol.push(elem);
        }
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
                if (!operation->leftAssociative_) {
                    std::swap(first, second);
                }
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

Sum::Sum(bool bin, bool la, bool pr, int prior) : Operation(bin, la, pr, prior) { }

double Sum::operator()(const double& first, const double& second) {
    return first + second;
}

Sub::Sub(bool bin, bool la, bool pr, int prior) : Operation(bin, la, pr, prior) { }

double Sub::operator()(const double& first, const double& second) {
    return first - second;
}

Mult::Mult(bool bin, bool la, bool pr, int prior) : Operation(bin, la, pr, prior) { }

double Mult::operator()(const double& first, const double& second) {
    return first * second;
}

Divide::Divide(bool bin, bool la, bool pr, int prior) : Operation(bin, la, pr, prior) { }

double Divide::operator()(const double& first, const double& second) {
    return first / second;
}