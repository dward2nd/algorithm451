#include <algorithm>
#include <ios>
#include <iostream>

int **_lcs_dp_init(const std::string &s1, const std::string &s2) {

    int **dp = new int *[s1.size() + 1];
    for (int i = 0; i <= s1.size(); ++i) {
        dp[i] = new int[s2.size() + 1];
        std::fill_n(dp[i], s1.size() + 1, -1);
    }

    return dp;
}

int _lcs_dp(const std::string &s1, const std::string &s2, int m, int n,
            int **dp) {
    if (m == 0 || n == 0)
        return 0;

    if (dp[m][n] != -1)
        return dp[m][n];

    if (s1[m - 1] == s2[n - 1])
        return dp[m][n] = 1 + _lcs_dp(s1, s2, m - 1, n - 1, dp);

    return dp[m][n] = std::max(_lcs_dp(s1, s2, m, n - 1, dp),
                               _lcs_dp(s1, s2, m - 1, n, dp));
}

std::string lcs(const std::string s1, const std::string s2) {
    int **dp = _lcs_dp_init(s1, s2);
    int i, j, k, l;

    std::string ret;
    i = s1.size(), j = s2.size();

    while (i && j) {
        if (_lcs_dp(s1, s2, i, j, dp) == _lcs_dp(s1, s2, i - 1, j, dp)) {
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
