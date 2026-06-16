#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#define S_FORM "Shrubbery Creation Form"
#define S_SIGN 145
#define S_EXEC 137

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    std::string target;

    void        performAction() const;

  public:
    ~ShrubberyCreationForm() {};
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &copy);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);

    class ShrubberyFailException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
};

#endif
