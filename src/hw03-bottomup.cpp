#include <algorithm>
#include <cstdlib>
#include <ios>
#include <iostream>

long int count_possible(int n, int m) {
    long int dp[n + 1];

    // initialize
    std::fill_n(dp, std::min(n + 1, m), 1);
    if (m <= n)
        dp[m] = 2;

    for (int i = m + 1; i <= n; ++i)
        dp[i] = dp[i - 1] + dp[i - m];

    return dp[n];
}

void hw03() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::cout << count_possible(n, m) << '\n';
}
