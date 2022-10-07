#include <algorithm>
#include <ios>
#include <iostream>

const int INF = 10000;

int attackCount(int n, int &k, int *damage) {
    std::sort(damage, damage + k);
    int min = INF;
    for (int i = k - 1; i >= 0; --i) {
        int count = n / damage[i];
        int leftover = n % damage[i];
        for (int j = i - 1; j >= 0 && leftover > 0; --j) {
            count += leftover / damage[j];
            leftover %= damage[j];
        }

        min = std::min(min, count);
    }

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
