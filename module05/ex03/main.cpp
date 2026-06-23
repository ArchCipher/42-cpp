#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <ctime>
#include <iostream>

void test_intern(const Intern &random_intern, const std::string &form_name,
                 const std::string &target, Bureaucrat &bureaucrat)
{
    AForm *f = NULL;

    std::cout << "-----\n";
    try
    {
        f = random_intern.makeForm(form_name, target);
        bureaucrat.signForm(*f);
        bureaucrat.executeForm(*f);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }
    delete (f);
}

int main()
{
    std::srand(std::time(NULL));
    Bureaucrat   adam("Adam", MAX_GRADE);
    // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    Bureaucrat   bob("Bob", 45);
    Bureaucrat   jim("Jim", MIN_GRADE);

    const Intern random_intern;
    test_intern(random_intern, "shrubbery creation", "home", bob);
    test_intern(random_intern, "robotomy request", "Bender", bob);
    test_intern(random_intern, "robotomy request", "Bender", jim);
    test_intern(random_intern, "presidential pardon", "Jim", adam);
    test_intern(random_intern, "random form", "Random target", bob);
}
