#include <algorithm>
#include <ios>
#include <iostream>
#include <limits>

int INF = 10000;

int attackCount(int n, int &k, int *damage, int *dp = nullptr) {
    if (dp == nullptr) {
        dp = new int[n + 1];
        dp[0] = 0;
        std::fill(dp + 1, dp + n + 1, INF);
    }

    if (n < 0)
        return INF;

    if (dp[n] != INF)
        return dp[n];

    for (int i = 0; i < k; ++i)
        dp[n] = std::min(dp[n], attackCount(n - damage[i], k, damage, dp) + 1);

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
