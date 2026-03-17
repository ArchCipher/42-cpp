#include "Brain.hpp"

Brain::Brain(const Brain &copy)
{
    setIdeas(copy.ideas);
}

Brain &Brain::operator=(const Brain &copy)
{
    if (this != &copy)
        setIdeas(copy.ideas);
    return (*this);
}

void Brain::setIdea(const std::string &my_idea, unsigned int i)
{
    if (i < MAX_IDEAS)
        ideas[i] = my_idea;
}

void Brain::setIdeas(const std::string (&my_ideas)[MAX_IDEAS])
{
    for (int i = 0; i < MAX_IDEAS; i++)
        ideas[i] = my_ideas[i];
}

const std::string &Brain::getIdea(unsigned int i) const
{
    static const std::string empty;

    if (i < MAX_IDEAS)
        return (ideas[i]);
    return (empty);
}
