#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form(const std::string &name, int sign_grade, int execute_grade)
    : name(name), isSigned(false), signGrade(sign_grade),
      executeGrade(execute_grade)
{
    if (sign_grade < MAX_GRADE || execute_grade < MAX_GRADE)
        throw GradeTooHighException();
    if (sign_grade > MIN_GRADE || execute_grade > MIN_GRADE)
        throw GradeTooLowException();
}

Form::Form(const Form &copy)
    : name(copy.name), isSigned(copy.isSigned), signGrade(copy.signGrade),
      executeGrade(copy.executeGrade)
{
}

Form &Form::operator=(const Form &copy)
{
    if (this != &copy)
        isSigned = copy.isSigned;
    return (*this);
}

const std::string &Form::getName() const
{
    return (name);
}

bool Form::getIsSigned() const
{
    return (isSigned);
}

int Form::getSignGrade() const
{
    return (signGrade);
}

int Form::getExecuteGrade() const
{
    return (executeGrade);
}

void Form::beSigned(Bureaucrat const &executor)
{
    if (executor.getGrade() > signGrade)
        throw GradeTooLowException();
    isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("grade too low");
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << form.getName() << ", with sign_grade " << form.getSignGrade()
        << ", execute_grade " << form.getExecuteGrade();
    if (form.getIsSigned())
        out << " is signed\n";
    else
        out << " is not signed\n";
    return (out);
}
