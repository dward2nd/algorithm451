#include <cstring>
#include <iostream>

#include "hw01.cpp"
#include "hw02.cpp"
#include "hw03.cpp"
#include "hw04.cpp"
#include "test.cpp"
#include "test2.cpp"
#include "test3.cpp"

typedef void (*hwMain)();

hwMain mains[] = {hw01, hw02, hw03, hw04, hwtest, hwtest2, hwtest3};

int main(int argc, char *argv[]) {
    bool prompt = strcmp(argv[argc - 1], "--no-prompt") != 0;

    if (prompt)
        std::cout << "==========\n"
                  << "[1] HW01 - Stern Brocot Path\n"
                  << "[2] HW02 - Sport Day\n"
                  << "[3] HW03 - Tiling\n"
                  << "[4] HW04 - Bambina\n"
                  << "[5] TEST - Hack Test\n"
                  << "[6] TEST2 - Pascal Triangle DP\n"
                  << "[7] TEST3 - LCS\n"
                  << "==========\n";

    char hw;
    if (prompt)
        std::cout << "\nHomework number: ";
    std::cin >> hw;

    hw -= '1';
    mains[hw]();

    return 0;
}
