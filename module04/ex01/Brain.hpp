#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

#define MAX_IDEAS 100

class Brain
{
    std::string ideas[MAX_IDEAS];

  public:
    virtual ~Brain();
    Brain();
    Brain(const Brain &copy);
    Brain             &operator=(const Brain &copy);

    void               setIdea(const std::string &my_idea, unsigned int i);
    void               setIdeas(const std::string (&my_ideas)[MAX_IDEAS]);
    const std::string &getIdea(unsigned int i) const;
};

#endif
