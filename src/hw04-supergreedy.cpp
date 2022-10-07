#include <algorithm>
#include <ios>
#include <iostream>

const int INF = 10000;

int attackCount(int n, int &k, int *damage) {
    std::sort(damage, damage + k);
    int count = n / damage[k - 1];
    int leftover = n % damage[k - 1];
    for (int j = k - 2; j >= 0 && leftover > 0; --j) {
        count += leftover / damage[j];
        leftover %= damage[j];
    }

    int min = std::min(INF, count);

    return min;
}

void hw04() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    int damage[k];
    for (int i = 0; i < k; ++i)
        std::cin >> damage[i];

    // answer
    std::cout << attackCount(n, k, damage);
}
