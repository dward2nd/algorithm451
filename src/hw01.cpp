#include <cstdint>
#include <iostream>
#include <vector>

std::vector<bool> getSternBrocotPath(std::uint_fast16_t n,
                                     std::uint_fast16_t m) {
    std::uint_fast16_t a1 = 0, a2 = 1, b1 = 1, b2 = 1, c1 = 1, c2 = 0;

    std::vector<bool> solution = {};
    double key = (double)n / m;

    while (b1 != n || b2 != m) {
        double a = (double)a1 / a2, b = (double)b1 / b2, c = (double)c1 / c2;

        if (key < b) {
            c1 = b1;
            c2 = b2;
            solution.push_back(0);
        } else {
            a1 = b1;
            a2 = b2;
            solution.push_back(1);
        }

        b1 = a1 + c1, b2 = a2 + c2;
    }

    return solution;
}

void hw01() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::uint_fast16_t n, m;
    std::cin >> n >> m;

    std::vector<bool> result = getSternBrocotPath(n, m);
    for (auto direction : result)
        if (direction)
            std::cout << 'R';
        else
            ˙ std::cout << 'L';
}
