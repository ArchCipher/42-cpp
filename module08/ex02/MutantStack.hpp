#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <stack>

/*
        Stack is a container adapter to provide stack.
        The class template acts as a wrapper to the underlying container
        - only a specific set of functions is provided.
        The stack pushes and pops the element from the back of the underlying
   container, known as the top of the stack.

        Subject:
        The std::stack container is very nice. Unfortunately, it is one of the
   only STL Containers that is NOT iterable. That’s too bad. But why would we
   accept this? Especially if we can take the liberty of butchering the original
   stack to create missing features. To repair this injustice, you have to make
   the std::stack container iterable. Write a MutantStack class. It will be
        implemented in terms of a std::stack. It will offer all its member
        functions, plus an additional feature: iterators.

        Implemented iterators:
        iterator, const_iterator, reverse_iterator, const_reverse_iterator
*/

template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
  public:
    typedef typename Container::iterator               iterator;
    typedef typename Container::const_iterator         const_iterator;
    typedef typename Container::reverse_iterator       reverse_iterator;
    typedef typename Container::const_reverse_iterator const_reverse_iterator;

    iterator                                           begin()
    {
        return (this->c.begin());
    }

    const_iterator begin() const
    {
        return (this->c.begin());
    }

    iterator end()
    {
        return (this->c.end());
    }

    const_iterator end() const
    {
        return (this->c.end());
    }

    reverse_iterator rbegin()
    {
        return (this->c.rbegin());
    }

    const_reverse_iterator rbegin() const
    {
        return (this->c.rbegin());
    }

    reverse_iterator rend()
    {
        return (this->c.rend());
    }

    const_reverse_iterator rend() const
    {
        return (this->c.rend());
    }
};

#endif
