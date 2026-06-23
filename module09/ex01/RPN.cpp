#include "RPN.hpp"
#include <climits>
#include <exception>

RPN::RPN(const RPN &copy) : st(copy.st) {}

RPN &RPN::operator=(const RPN &copy)
{
	if (this != &copy)
		st = copy.st;
	return *this;
}

int RPN::evaluate(const std::string &s)
{
	if (!st.empty())
		st = std::stack<int>();
    for (std::string::const_iterator it = s.begin(); it != s.end(); it++)
    {
        if (*it >= '0' && *it <= '9')
            st.push(static_cast<int>(*it - '0'));
        else
        {
            int b = pop();
            int a = pop();
            st.push(calculate(a, b, *it));
        }
        it++;
        if (it == s.end())
            break;
        if (*it != ' ' || it + 1 == s.end())
            throw std::exception();
    }
    if (st.size() != 1)
        throw std::exception();
    return pop();
}

static bool is_prod_out_of_range(const int &a, const int &b)
{
	if (a > 0 && ((b > 0 && a > INT_MAX / b) || (b < 0 && b < INT_MIN / a)))
		return true;
    if(a < 0 && ((b > 0 && a < INT_MIN / b) || (b < 0 && b < INT_MAX / a)))
		return true;
	return false;
}

int RPN::calculate(const int &a, const int &b, char c)
{
    switch (c)
    {
        case '+':
            if ((b > 0 && a > INT_MAX - b) || (b < 0 && a < INT_MIN - b))
                throw std::exception();
            return (a + b);
        case '-':
            if ((b < 0 && a > INT_MAX + b) || (b > 0 && a < INT_MIN + b))
                throw std::exception();
            return (a - b);
        case '*':
            if (is_prod_out_of_range(a, b))
                throw std::exception();
            return (a * b);
        case '/':
            if (b == 0 || (a == INT_MIN && b == -1))
                throw std::exception();
            return (a / b);
        default:
            throw std::exception();
    }
}

int RPN::pop()
{
    if (st.empty())
        throw std::exception();
    int num = st.top();
    st.pop();
    return num;
}
