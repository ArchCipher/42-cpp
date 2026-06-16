#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
    // NOLINTNEXTLINE(cppcoreguidelines-avoid-const-or-ref-data-members)
    const std::string name;
    bool              isSigned;
    // NOLINTNEXTLINE(cppcoreguidelines-avoid-const-or-ref-data-members)
    const int         signGrade;
    // NOLINTNEXTLINE(cppcoreguidelines-avoid-const-or-ref-data-members)
    const int         executeGrade;

  public:
    virtual ~AForm() {};
    AForm(const std::string &name, int sign_grade, int execute_grade);
    AForm(const AForm &copy);
    AForm             &operator=(const AForm &copy);

    const std::string &getName() const;
    bool               getIsSigned() const;
    int                getSignGrade() const;
    int                getExecuteGrade() const;

    void               beSigned(Bureaucrat const &executor);
    void               execute(Bureaucrat const &executor) const;
    virtual void       performAction() const = 0;

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

    class FormNotSignedException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif
