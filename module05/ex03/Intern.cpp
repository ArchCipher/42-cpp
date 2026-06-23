#include "Intern.hpp"
#include <iostream>

static const std::string form_names[] = {
    "shrubbery creation", "robotomy request", "presidential pardon"};
static const int max_forms = sizeof(form_names) / sizeof(form_names[0]);

Intern::Intern(const Intern &copy)
{
    (void)copy;
}

Intern &Intern::operator=(const Intern &copy)
{
    (void)copy;
    return (*this);
}

// NOLINTNEXTLINE(readability-convert-member-functions-to-static)
AForm *Intern::makeForm(const std::string &form_name,
                        const std::string &target) const
{
    int i = 0;
    for (; i < max_forms; i++)
    {
        if (form_names[i] == form_name)
        {
            std::cout << "Intern creates " << form_name << '\n';
            break;
        }
    }
    switch (i)
    {
        case 0:
            return (new ShrubberyCreationForm(target));
        case 1:
            return (new RobotomyRequestForm(target));
        case 2:
            return (new PresidentialPardonForm(target));
        default:
            throw InvalidForm();
    }
}

const char *Intern::InvalidForm::what() const throw()
{
    return ("invalid form name");
}
