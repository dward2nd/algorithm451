#include <algorithm>
#include <cstdlib>
#include <ios>
#include <iostream>

long int count_possible(int n, int m, long int *dp = nullptr) {
    if (dp == nullptr) {
        dp = (long int *)std::malloc(sizeof(long int) * (n + 1));
        std::fill_n(dp, n + 1, -1);
    }

    if (dp[n] != -1)
        return dp[n];

    if (n < m)
        return dp[n] = 1;

    if (n == m)
        return dp[n] = 2;

    return dp[n] = count_possible(n - 1, m, dp) + count_possible(n - m, m, dp);
}

void hw03() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::cout << count_possible(n, m) << '\n';
}
