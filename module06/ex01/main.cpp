#include "Serializer.hpp"

int main()
{
    // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    Data      data = {42, 42, 42.2f, 42.2};
    Data     *ptr1 = &data;
    uintptr_t u = Serializer::serialize(ptr1);
    Data     *ptr2 = Serializer::deserialize(u);
    std::cout << "ptr1: " << ptr1 << "\n"
              << "ptr2: " << ptr2 << "\n\n"
              << "ptr1.raw: \n"
              << *ptr1 << "\n"
              << "ptr2.raw: \n"
              << *ptr2 << "\n";
}
