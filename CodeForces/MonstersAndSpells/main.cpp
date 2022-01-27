#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<long long, long long> p1, pair<long long, long long> p2) {
    if (p1.first == p2.first)
        return p1.second > p2.second;
    return p1.first < p2.first;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<long long> k(n), h(n);
        for (int i = 0; i < n; i++)
            cin >> k[i];
        for (int i = 0; i < n; i++)
            cin >> h[i];
        vector<pair<long long, long long>> mons;
        for (int i = 0; i < n; i++)
            mons.push_back(make_pair(k[i] - h[i] + 1, k[i]));
        sort(mons.begin(), mons.end(), cmp);
        long long ans = 0LL, ti = 0LL, x = 1;
        int i = 0;
        while (i < n) {
            if (mons[i].second < ti) {
                i++;
                continue;
            }
            pair<long long, long long> p = mons[i];
            if (ti < p.first) {
                x = p.second - p.first + 1;
                ans += ((x * (x + 1)) / 2);
            } else {
                ans += (((p.second - ti) * (2 * x + p.second - ti + 1)) / 2);
                x += (p.second - ti);
            }
            ti = p.second;
            i++;
        }

        cout << ans << endl;
    }

    return 0;
}
