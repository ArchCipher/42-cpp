#include "Bureaucrat.hpp"

void test_invalid_grade(int grade)
{
    std::cout << "-----\n";
    try
    {
        Bureaucrat random("Random", grade);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }
}

void test_grade_change(Bureaucrat &b, void (Bureaucrat::*action)())
{
    try
    {
        std::cout << "-----\n" << b;
        (b.*action)();
        std::cout << b;
        (b.*action)();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }
}

void test_assignment(Bureaucrat &bob)
{
    Bureaucrat jim("Jim", MAX_GRADE + 1);
    std::cout << "-----\n" << jim;
    jim = bob;
    std::cout << jim;
}

void test_set_grade(Bureaucrat &bob)
{
    std::cout << "-----\n";
    try
    {
        // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
        bob.setGrade(200);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }
}

int main()
{
    test_invalid_grade(0);
    // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    test_invalid_grade(200);
    Bureaucrat bob("Bob", MAX_GRADE + 1);
    test_grade_change(bob, &Bureaucrat::incrementGrade);
    bob.setGrade(MIN_GRADE - 1);
    test_grade_change(bob, &Bureaucrat::decrementGrade);
    test_assignment(bob);
    test_set_grade(bob);
}
