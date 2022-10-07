#include <algorithm>
#include <ios>
#include <iostream>
#include <limits>

int INF = 10000;

int attackCount(int n, int &k, int *damage) {
    int dp[n + 1];
    dp[0] = 0;
    std::fill(dp + 1, dp + n + 1, INF);

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < k; ++j) {
            int d = i - damage[j];
            if (d >= 0)
                dp[i] = std::min(dp[i], dp[d] + 1);
        }
    }

    return dp[n];
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
