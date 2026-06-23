#ifndef FORM_HPP
#define FORM_HPP

#include <iosfwd>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
    // NOLINTNEXTLINE(cppcoreguidelines-avoid-const-or-ref-data-members)
    const std::string name;
    bool              isSigned;
    // NOLINTNEXTLINE(cppcoreguidelines-avoid-const-or-ref-data-members)
    const int         signGrade;
    // NOLINTNEXTLINE(cppcoreguidelines-avoid-const-or-ref-data-members)
    const int         executeGrade;

  public:
    ~Form() {};
    Form(const std::string &name, int sign_grade, int execute_grade);
    Form(const Form &copy);
    Form              &operator=(const Form &copy);

    const std::string &getName() const;
    bool               getIsSigned() const;
    int                getSignGrade() const;
    int                getExecuteGrade() const;

    void               beSigned(Bureaucrat const &executor);

    class GradeTooHighException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
