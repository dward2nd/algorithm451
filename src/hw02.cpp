#include <algorithm>
#include <ios>
#include <iostream>
#include <utility>
#include <vector>

typedef std::pair<int, int> interval;

int max_event_count(const int &n, std::vector<interval> &events) {
    int i = 0, count = 1;
    for (int j = 1; j < n; ++j) {
        if (events[i].first <= events[j].second &&
            events[i].second <= events[j].second &&
            events[i].first <= events[j].first) {
            ++count;
            i = j;
        }
    }

    return count;
}

void hw02() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--) {
        int n;
        std::cin >> n;

        int i;
        i = n;

        std::vector<std::pair<int, int>> events;
        while (i--) {
            int start, end;
            std::cin >> start >> end;
            events.push_back({end, start});
        }
        std::sort(events.begin(), events.end());

        std::cout << max_event_count(n, events) << '\n';
    }
}
