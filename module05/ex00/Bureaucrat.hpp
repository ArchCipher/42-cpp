#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iosfwd>
#include <string>

#define MAX_GRADE 1
#define MIN_GRADE 150

/*
        Bureaucrat class with attritube grade in range[1, 150]

        GradeTooHighException and GradeTooLowException are
        nested classes that inherit from class std::exception.

  NOTE:
  [cppcoreguidelines-avoid-const-or-ref-data-members] warns about const or
  reference data members. This is ignored as the subject instructs on using
  const name -> hence assignment would mean no change in name.

  in macOS what() is defined as:
        virtual const char *what() const _NOEXCEPT;

        in glibc what is defined as:
        virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
*/
class Bureaucrat
{
    // NOLINTNEXTLINE(cppcoreguidelines-avoid-const-or-ref-data-members)
    const std::string name;
    int               grade;

  public:
    ~Bureaucrat(){};
    Bureaucrat(const std::string &name);
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &copy);
    Bureaucrat        &operator=(const Bureaucrat &copy);

    const std::string &getName() const;
    int                getGrade() const;
    void               setGrade(int grade);
    void               incrementGrade();
    void               decrementGrade();

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

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bc);

#endif
