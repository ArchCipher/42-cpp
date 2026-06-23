#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm(S_FORM, S_SIGN, S_EXEC), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
    : AForm(copy), target(copy.target)
{
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    if (this != &copy)
    {
        AForm::operator=(copy);
        target = copy.target;
    }
    return (*this);
}

void ShrubberyCreationForm::performAction() const
{
    std::ofstream my_file((target + "_shrubbery").c_str());
    if (!my_file.is_open())
        throw ShrubberyFailException();

    my_file << "    *\n"
            << "   /.\\\\\n"
            << "  /o..\\\\\n"
            << "  /..o\\\\\n"
            << " /.o..o\\\\\n"
            << " /...o.\\\\\n"
            << "/.o.....\\\\\n"
            << "^^^[_]^^^\n";
}

const char *ShrubberyCreationForm::ShrubberyFailException::what() const throw()
{
    return ("cannot open file");
}
