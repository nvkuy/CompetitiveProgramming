#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long t, n, m, x, ai;
    cin >> t;
    while (t--) {
        cin >> n >> m >> x;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<int> ans(n, 0);
        vector<pair<long long, int>> a;
        for (int i = 0; i < n; i++) {
            cin >> ai;
            a.push_back({ai, i});
        }
        sort(a.begin(), a.end(), greater<pair<long long, int>>());
        for (int i = 1; i <= m; i++) {
            pq.push({a[i - 1].first, i});
            ans[a[i - 1].second] = i;
        }
        for (int i = m; i < n; i++) {
            pair<long long, int> tmp = pq.top();
            pq.pop();
            tmp.first += a[i].first;
            pq.push(tmp);
            ans[a[i].second] = tmp.second;
        }
        bool iok = true;
        pair<long long, int> p1 = pq.top(), p2;
        while (pq.size() > 1)
            pq.pop();
        p2 = pq.top();
        if (llabs(p2.first - p1.first) > x)
            iok = false;
        if (!iok) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }

    return 0;
}
