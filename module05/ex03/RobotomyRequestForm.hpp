#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

#define R_FORM "Robotomy Request Form"
#define R_SIGN 72
#define R_EXEC 45

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
    std::string target;

    void        performAction() const;

  public:
    ~RobotomyRequestForm() {};
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &copy);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);

    class RobotomyFailException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
};

#endif
