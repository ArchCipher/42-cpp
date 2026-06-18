#include "MutantStack.hpp"

#include <iostream>
#include <list>

template <typename T> void test_iterator(T &x)
{
    typename T::iterator it = x.begin();
    typename T::iterator ite = x.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    typename T::reverse_iterator rit = x.rbegin();
    std::cout << "rbegin: " << *rit << std::endl;
    ++rit;
    std::cout << *rit << std::endl;
}

template <typename T> void fill_mutant_stack(T &mstack)
{
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.top() << std::endl;
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
}

template <typename T> void fill_other(T &other)
{
    other.push_back(5);
    other.push_back(17);
    std::cout << other.back() << std::endl;
    other.pop_back();
    std::cout << other.back() << std::endl;
    std::cout << other.size() << std::endl;
    other.push_back(3);
    other.push_back(5);
    other.push_back(737);
    other.push_back(0);
}

// NOLINTNEXTLINE(bugprone-exception-escape)
int main()
{
    std::cout << "-------test mutant stack-------\n";
    MutantStack<int> mstack;
    fill_mutant_stack(mstack);
    test_iterator(mstack);
    std::stack<int> s(mstack);
    std::cout << "-------test mutant list-------\n";
    MutantStack<int, std::list<int> > mlist;
    fill_mutant_stack(mlist);
    test_iterator(mlist);
    std::stack<int, std::list<int> > l(mlist);
    std::cout << "-------compare with list-------\n";
    std::list<int> lst;
    fill_other(lst);
    test_iterator(lst);
    std::cout << "-------compare with deque-------\n";
    std::deque<int> dq;
    fill_other(dq);
    test_iterator(dq);
    return 0;
}
