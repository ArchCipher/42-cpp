#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm(R_FORM, R_SIGN, R_EXEC), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
    : AForm(copy), target(copy.target)
{
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    if (this != &copy)
    {
        AForm::operator=(copy);
        target = copy.target;
    }
    return (*this);
}

void RobotomyRequestForm::performAction() const
{
    std::cout << "*** DRILLING NOISES ***\n";
    if (arc4random() % 2)
        std::cout << target << " has been robotomized\n";
    else
    {
        std::cout << "Robotomy failed\n";
        throw RobotomyFailException();
    }
}

const char *RobotomyRequestForm::RobotomyFailException::what() const throw()
{
    return ("robotomy failed");
}
