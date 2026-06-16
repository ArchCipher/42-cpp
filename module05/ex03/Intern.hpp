#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

class AForm;

class Intern
{
  public:
    ~Intern() {};
    Intern() {};
    Intern(const Intern &copy);
    Intern &operator=(const Intern &copy);

    AForm  *makeForm(const std::string &form_name,
                     const std::string &target) const;

    class InvalidForm : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
};

#endif
