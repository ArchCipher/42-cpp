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

    void               setIdea(const std::string &Idea, unsigned int i);
    void               setIdeas(const std::string (&Ideas)[MAX_IDEAS]);
    const std::string &getIdea(unsigned int i) const;
    const std::string *getIdeas() const;
};

#endif
