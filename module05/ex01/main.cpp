#include "Bureaucrat.hpp"
#include "Form.hpp"

void test_sign_form(Bureaucrat &a, int sign_grade)
{
    std::cout << "-----\n";
    try
    {
        Form form("form", sign_grade, sign_grade);
        a.signForm(form);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }
}

int main()
{
    const int  test_sign_grade = 72;
    Bureaucrat bob("Bob", MIN_GRADE);
    test_sign_form(bob, test_sign_grade);
    Bureaucrat adam("Adam", MAX_GRADE);
    test_sign_form(adam, test_sign_grade);
    // NOLINENEXTLINE(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    test_sign_form(adam, 200);
}
