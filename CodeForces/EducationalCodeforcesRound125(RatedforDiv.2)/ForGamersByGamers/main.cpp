#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

bool cmphr(pair<long long, long long> h1, pair<long long, long long> h2) {
    if ((h1.second / h1.first) == (h2.second / h2.first))
        return (h1.second % h1.first) > (h2.second % h2.first);
    return (h1.second / h1.first) > (h2.second / h2.first);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, c, m, ci, di, hi;
    cin >> n >> c;
    vector<pair<long long, long long>> hrs;
    for (int i = 0; i < n; i++) {
        cin >> ci >> di >> hi;
        hrs.push_back(make_pair(ci, di * hi));
    }
    sort(hrs.begin(), hrs.end(), cmphr);
    cin >> m;
    vector<pair<long long, int>> mons;
    for (int i = 0; i < m; i++) {
        cin >> di >> hi;
        mons.push_back(make_pair(di * hi, i));
    }
    sort(mons.begin(), mons.end());
    vector<int> rs(m, - 1);
    int p = 0, k;
    for (int j = 0; j < mons.size(); j++) {
        long long ans = 2e18, tmp;
        k = p;
        for (int i = p; i < n; i++) {
            tmp = (mons[j].first / (hrs[i].second)) + 1LL;
            ans = min(ans, tmp * hrs[i].first);
            if (ans > c)
                p = i + 1;
        }
        p = k;
        if (ans > c)
            break;
        rs[mons[j].second] = ans;
    }
    for (int i = 0; i < m; i++)
        cout << rs[i] << ' ';

    return 0;
}
