#include <iostream>

#include "HW01.cpp"

typedef void (*hwMain)();

hwMain mains[] = {
    hw01
};

int main() {
    std::cout << "==========\n"
        << "[1] HW01 - Stern Brocot Path\n"
        << "==========\n";

    char hw;
    std::cout << "Homework number: ";
    std::cin >> hw;

    // if (hw >= 'a' && hw <= 'z') {
    //     hw -= 'a';
    //     tests[hw]();
    // } else {
    hw -= '1';
    mains[hw]();
    // }

    return 0;
}
