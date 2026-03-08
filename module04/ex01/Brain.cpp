#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called\n";
}

Brain::Brain(const Brain &copy)
{
    std::cout << "Brain copy constructor called\n";
    setIdeas(copy.ideas);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called\n";
}

Brain &Brain::operator=(const Brain &copy)
{
    if (this != &copy)
    {
        setIdeas(copy.ideas);
        std::cout << "Brain assignment operator called\n";
    }
    return (*this);
}

void Brain::setIdea(const std::string &Idea, unsigned int i)
{
    if (i < MAX_IDEAS)
        ideas[i] = Idea;
}

void Brain::setIdeas(const std::string (&Ideas)[MAX_IDEAS])
{
    for (int i = 0; i < MAX_IDEAS; i++)
        ideas[i] = Ideas[i];
}

const std::string &Brain::getIdea(unsigned int i) const
{
    static const std::string empty;

    if (i < MAX_IDEAS)
        return (ideas[i]);
    return (empty);
}

const std::string *Brain::getIdeas() const
{
    return (ideas);
}
