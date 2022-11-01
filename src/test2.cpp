#include <iostream>
#include <unordered_map>

typedef std::unordered_map<unsigned int, unsigned long long> *memo_inner;
typedef std::unordered_map<unsigned int, memo_inner> *memo;

unsigned long long pascal(unsigned int n, unsigned int r, memo dp = nullptr) {
    if (dp == nullptr)
        dp = new std::unordered_map<unsigned int, memo_inner>();

    if (n == 0 || r == 0 || n == r) {
        std::cout << "pascal(" << n << ", " << r << ") = ";
        std::cout << 1 << '\n';
        return 1;
    }

    if (dp->find(n) == dp->end())
        dp->insert(
            {n, new std::unordered_map<unsigned int, unsigned long long>()});

    memo_inner dp_inner = dp->at(n);
    if (dp_inner->find(r) == dp_inner->end())
        dp_inner->insert({r, pascal(n - 1, r, dp) + pascal(n - 1, r - 1, dp)});

    std::cout << "pascal(" << n << ", " << r << ") = ";
    std::cout << (dp_inner->at(r)) << '\n';
    return dp_inner->at(r);
}

void hwtest2() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned int n, r;
    std::cin >> n >> r;

    std::cout << pascal(n, r) << '\n';
}
