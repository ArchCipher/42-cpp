# <p align="center"> 42 C++ Modules </p>

**Objective:**  Work through the full 42 C++ curriculum (modules 00–09) in **C++98**, with a focus on clean design and correct ownership.

**Overview:**  
Each module introduces a small concept set and a set of exercises, building from basic classes up to abstract interfaces and later template/algorithm work.

---

## Modules and Topics

- **Module 00** – Introduction to OOP and `std::string`
  Focus: namespaces, simple classes, member functions, stdio streams,
initialization lists, static, const, and other basic syntax

- **Module 01** – Memory allocation, references, pointers and `switch`
  Focus: stack vs heap, `new`/`delete`, references, pointers, simple RAII patterns.

- **Module 02** – Ad-hoc polymorphism, operator overloading, orthodox canonical form 
  Focus: fixed-point class (`Fixed`), arithmetic and comparison operators, correct canonical form (constructor, copy constructor, assignment, destructor).

- **Module 03** – Inheritance
  Focus: base/derived classes (`ClapTrap`, `ScavTrap`, `FragTrap`, `DiamondTrap`), overriding, access specifiers, simple polymorphism.

- **Module 04** – Subtype polymorphism, abstract classes and interfaces
  Focus: virtual destructors, abstract classes (`Animal`, `AMateria`), interfaces (`ICharacter`, `IMateriaSource`), deep copy and ownership.

- **Module 05** – Repetition and exceptions
  Focus: exception-safe code, error handling patterns, control flow with exceptions.

- **Module 06** – C++ casts
  Focus: `static_cast`, `dynamic_cast`, `reinterpret_cast`, `const_cast`, and when each is appropriate.

- **Module 07** – C++ templates (**In progress**)
  Focus: function templates, class templates, generic algorithms.

- **Module 08** – Templated containers, iterators, algorithms (**Not started**)  
  Focus: container-like classes, iterators, simple algorithm implementations using templates.

- **Module 09** – STL (**Not started**)  
  Focus: STL containers and algorithms within the project constraints.

Each module follows the 42 subject structure and has its own `Makefile` and test mains.

---

## Build and Run

Typical workflow for a given exercise:

```bash
# Go to a specific exercise
cd module03/ex01

# Build with the exercise Makefile
make

# Run the resulting binary
./a.out
```

All code is written against **C++98**, with the usual 42 flags:

- `-Wall -Wextra -Werror -std=c++98`

---

## Conventions and Checks

- **Standard:** C++98 only (no C++11 features such as delegating constructors, `auto`, `nullptr`, range-for, etc.).
- **Namespaces:** `using namespace <ns_name>` is explicitly forbidden. Selective using-declarations (`using std::cout;`, `using std::string;`, etc.) are not mentioned in the subject and are used where they improve readability.
- **Subject rules (Allowed / Forbidden):**
  - Standard library is allowed and preferred over C equivalents.
  - No external libraries (Boost, etc.), no C++11 or later.
  - `*printf()`, `*alloc()`, and `free()` are forbidden.
  - `using namespace <ns_name>` and `friend` are forbidden.
  - STL containers and `<algorithm>` are only allowed in modules 08 and 09.

- **Style (self-imposed):**
  - Clear class and method names; one main responsibility per class where possible.
  - Minimal, focused comments explaining non-obvious design decisions.
  - Formatting enforced by `.clang-format` (LLVM base): 4-space indent, 80-column limit, Allman braces, aligned consecutive declarations.
  - Static analysis via `.clang-tidy`: C++98-safe checks, modernize checks disabled, readability and bugprone checks kept where they do not conflict with the subjects.
  - Both tools run from the project root or through VS Code.

---

## Learning Focus

- Build a solid foundation in **C++98** while following 42's constraints.
- Practice:
  - Resource management and RAII.
  - Copy semantics (copy constructor, assignment operator, destructor).
  - Inheritance and polymorphism with correct ownership.
  - Exceptions, casts, templates, and basic STL usage (in later modules).
- Keep the exercises **readable and testable**, with dedicated test mains where the subjects are light on edge cases.

For implementation details and tests, see the individual module and exercise directories.

---

## Clang tool commands

### clang-format

```sh
# Run clang-format from the repo root or under each module
clang-format -i $(find . -name "*.cpp" -o -name "*.hpp")
```

### clang-tidy

```sh
# Run clang-tidy on individual files
clang-tidy main.cpp -- -std=c++98 -Wall -Werror -Wextra -I.
clang-tidy Zombie.cpp -- -std=c++98 -Wall -Werror -Wextra -I.

# or
clang-tidy $(find . -name "*.cpp" -o -name "*.hpp") -- -std=c++98 -Wall -Werror -Wextra
```

---

## References

[CPP basics](https://www.youtube.com/watch?v=wN0x9eZLix4)

[IO Manipulators](https://en.cppreference.com/w/cpp/io/manip.html): setfill, setw, setprecision

[String class](https://en.cppreference.com/w/cpp/string/basic_string.html): length, empty, find, npos, getline

[Howard Hinnant: How I Declare My class And Why](https://howardhinnant.github.io/classdecl.html)

[CppCoreGuidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#rc-order)
- C.47: Define and initialize data members in the order of member declaration
- C.48: Prefer default member initializers to member initializers in constructors for constant initializers

[clang-format](https://clang.llvm.org/docs/ClangFormatStyleOptions.html)

[Compiler flags](https://gcc.gnu.org/onlinedocs/gcc/Option-Index.html#Option-Index)

---
