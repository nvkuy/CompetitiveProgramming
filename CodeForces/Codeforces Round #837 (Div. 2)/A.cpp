#include <bits/stdc++.h>
using namespace std;

int main() {

    int t, n, ai;
    cin >> t;
    while (t--) {
        cin >> n;
        map<int, long long> cnt;
        for (int i = 0; i < n; i++) {
            cin >> ai;
            cnt[ai]++;
        }
        auto p1 = *cnt.begin(), p2 = *cnt.rbegin();
        if (p1.first == p2.first)
            cout << p2.second * (p2.second - 1LL) << endl;
        else
            cout << p1.second * p2.second * 2LL << endl;
    }

    return 0;
}