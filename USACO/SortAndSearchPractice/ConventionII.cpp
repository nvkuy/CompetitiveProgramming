#include <bits/stdc++.h>
using namespace std;

struct cow {
    int id, arrive, time;
    bool operator < (const cow &c) const {
        return id < c.id;
    }
};

bool cmp(const cow &c1, const cow &c2) {
    if (c1.arrive == c2.arrive)
        return c1.id < c2.id;
    return c1.arrive < c2.arrive;
}

int main() {

    if (fopen("convention2.in", "r")) {
        freopen("convention2.in", "r", stdin);
        freopen("convention2.out", "w", stdout);
    }

    int n;
    cin >> n;
    vector<cow> cows;
    for (int i = 1; i <= n; i++) {
        int a, t;
        cin >> a >> t;
        cows.push_back({i, a, t});
    }
    sort(cows.begin(), cows.end(), cmp);
    set<cow> in_queue;
    int time = cows[0].arrive, j = 0, ans = 0;
    while (true) {
        if (j == n && in_queue.size() == 0) break;
        while (j < n && time >= cows[j].arrive) {
            in_queue.insert(cows[j]);
            j++;
        }
        if (in_queue.size() == 0) {
            time = cows[j].arrive;
            continue;
        }
        ans = max(ans, time - in_queue.begin()->arrive);
        time += in_queue.begin()->time;
        in_queue.erase(in_queue.begin());
    }
    cout << ans << endl;

    return 0;
}
