#include <cstring>
#include <iostream>

#include "hw01.cpp"
#include "hw02.cpp"

typedef void (*hwMain)();

hwMain mains[] = {hw01, hw02};

int main(int argc, char *argv[]) {
    bool prompt = strcmp(argv[argc - 1], "--no-prompt") != 0;

    if (prompt)
        std::cout << "==========\n"
                  << "[1] HW01 - Stern Brocot Path\n"
                  << "[2] HW02 - Sport Day\n"
                  << "==========\n";

    char hw;
    if (prompt)
        std::cout << "\nHomework number: ";
    std::cin >> hw;

    hw -= '1';
    mains[hw]();

    return 0;
}
