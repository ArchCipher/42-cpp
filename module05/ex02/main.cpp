#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <ctime>

void test_form(Bureaucrat &a, AForm *form)
{
    std::cout << "-----\n";
    if (!form)
        return;
    a.signForm(*form);
    a.executeForm(*form);
}

class InvalidForm : public AForm
{
    void performAction() const {}

  public:
    InvalidForm(int sign_grade, int execute_grade)
        : AForm("invalid form", sign_grade, execute_grade)
    {
    }
};

int main()
{
    std::srand(std::time(NULL));
    Bureaucrat adam("Adam", MAX_GRADE);
    // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    Bureaucrat bob("Bob", 45);
    Bureaucrat jim("Jim", MIN_GRADE);
    try
    {
        ShrubberyCreationForm form1("home");
        test_form(jim, &form1);
        test_form(bob, &form1);
        RobotomyRequestForm form2("target");
        test_form(bob, &form2);
        PresidentialPardonForm form3("target");
        test_form(adam, &form3);
        std::cout << "-----\n";
        // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
        InvalidForm invalid_form(200, 200);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }
}
