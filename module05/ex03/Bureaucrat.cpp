#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name) : name(name), grade(MIN_GRADE)
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : name(name), grade(grade)
{
    if (grade < MAX_GRADE)
        throw Bureaucrat::GradeTooHighException();
    if (grade > MIN_GRADE)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
    : name(copy.name), grade(copy.grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
    if (this != &copy)
        grade = copy.grade;
    return (*this);
}

const std::string &Bureaucrat::getName() const
{
    return (name);
}

int Bureaucrat::getGrade() const
{
    return (grade);
}

void Bureaucrat::setGrade(int grade)
{
    if (grade < MAX_GRADE)
        throw GradeTooHighException();
    if (grade > MIN_GRADE)
        throw GradeTooLowException();
    this->grade = grade;
}

void Bureaucrat::incrementGrade()
{
    if (grade == MAX_GRADE)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade == MIN_GRADE)
        throw GradeTooLowException();
    grade++;
}

void Bureaucrat::signForm(AForm &form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << name << " couldn't sign " << form.getName() << " because "
                  << e.what() << '\n';
    }
}

void Bureaucrat::executeForm(AForm const &form) const
{
    try
    {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << name << " couldn't execute " << form.getName()
                  << " because " << e.what() << '\n';
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("grade too low");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bc)
{
    out << bc.getName() << ", bureaucrat grade " << bc.getGrade() << '\n';
    return (out);
}
