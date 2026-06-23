#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN
{
    std::stack<int> st;

    static int      calculate(const int &a, const int &b, char c);
    int             pop();

  public:
    ~RPN() {};
    RPN() {};
	RPN(const RPN &copy);
	RPN &operator=(const RPN &copy);

    int evaluate(const std::string &s);
};

#endif
