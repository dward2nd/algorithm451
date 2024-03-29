#include <algorithm>
#include <ios>
#include <iostream>

int **_lcs_dp(const std::string &s1, const std::string &s2) {
    int **dp = new int *[s1.size() + 1];
    int i, j, k, l;

    for (int i = 0; i <= s1.size(); ++i)
        dp[i] = new int[s2.size() + 1];

    for (i = 0; i <= s1.size(); ++i)
        dp[i][0] = 0;
    for (i = 0; i <= s2.size(); ++i)
        dp[0][i] = 0;

    for (i = 1; i <= s1.size(); ++i) {
        for (j = 1; j <= s2.size(); ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else
                dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);

            // uncomment to print the DP table on each iteration.
            // for (k = 0; k <= s1.size(); ++k) {
            //     for (l = 0; l <= s2.size(); ++l) {
            //         std::cout << dp[k][l] << ' ';
            //     }
            //     std::cout << '\n';
            // }
            // std::cout << '\n';
        }
    }

    return dp;
}

std::string lcs(const std::string s1, const std::string s2) {
    int **dp = _lcs_dp(s1, s2);
    int i, j, k, l;

    std::string ret;
    i = s1.size(), j = s2.size();

    while (i && j) {
        if (dp[i][j] == dp[i - 1][j]) {
            --i;
        } else if (s1[i - 1] == s2[j - 1]) {
            ret.push_back(s1[i - 1]);
            --i;
            --j;
        } else {
            --j;
        }
    }

    std::reverse(ret.begin(), ret.end());
    return ret;
}

void hwtest3() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s1, s2;
    std::cin >> s1 >> s2;

    std::cout << lcs(s1, s2);
}
