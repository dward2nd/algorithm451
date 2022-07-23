#include <iostream>

#include "hw01.cpp"

typedef void (*hwMain)();

hwMain mains[] = {
    hw01
};

int main() {
    std::cout << "==========\n"
        << "[1] HW01 - Stern Brocot Path\n"
        << "==========\n";

    char hw;
    std::cout << "\nHomework number: ";
    std::cin >> hw;

    hw -= '1';
    mains[hw]();

    return 0;
}

