#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm(const std::string &name, int sign_grade, int execute_grade)
    : name(name), isSigned(false), signGrade(sign_grade),
      executeGrade(execute_grade)
{
    if (sign_grade < MAX_GRADE || execute_grade < MAX_GRADE)
        throw GradeTooHighException();
    if (sign_grade > MIN_GRADE || execute_grade > MIN_GRADE)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &copy)
    : name(copy.name), isSigned(copy.isSigned), signGrade(copy.signGrade),
      executeGrade(copy.executeGrade)
{
}

AForm &AForm::operator=(const AForm &copy)
{
    if (this != &copy)
        isSigned = copy.isSigned;
    return (*this);
}

const std::string &AForm::getName() const
{
    return (name);
}

bool AForm::getIsSigned() const
{
    return (isSigned);
}

int AForm::getSignGrade() const
{
    return (signGrade);
}

int AForm::getExecuteGrade() const
{
    return (executeGrade);
}

void AForm::beSigned(Bureaucrat const &executor)
{
    if (executor.getGrade() > signGrade)
        throw GradeTooLowException();
    isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (!isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > executeGrade)
        throw GradeTooLowException();
    performAction();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("grade too low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return ("form not signed");
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << form.getName() << ", with sign_grade " << form.getSignGrade()
        << ", execute_grade " << form.getExecuteGrade();
    if (form.getIsSigned())
        out << " is signed\n";
    else
        out << " is not signed\n";
    return (out);
}
