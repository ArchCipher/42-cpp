#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#define P_FORM "Presidential Pardon Form"
#define P_SIGN 25
#define P_EXEC 5

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
    std::string target;

    void        performAction() const;

  public:
    ~PresidentialPardonForm(){};
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &copy);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
};

#endif
