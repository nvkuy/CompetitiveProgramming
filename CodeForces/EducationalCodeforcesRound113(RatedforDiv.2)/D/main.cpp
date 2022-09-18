#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

bool cmpY(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second < p2.second;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, m, k, maxCor = 1e6;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        vector<int> a(n), b(m), fx(maxCor + 1, 0), fy(maxCor + 1, 0);
        vector<pair<int, int>> cor(k);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        for (int i = 0; i < k; i++) {
            cin >> cor[i].first >> cor[i].second;
            fx[cor[i].first]++, fy[cor[i].second]++;
        }
        for (int i = 1; i <= maxCor; i++)
            fx[i] += fx[i - 1];
        for (int i = 1; i <= maxCor; i++)
            fy[i] += fy[i - 1];
        sort(cor.begin(), cor.end(), cmpY);
        long long ans = 0;
        for (int i = 0; i < cor.size(); i++) {
            int nearestX = lower_bound(a.begin(), a.end(), cor[i].first) - a.begin();
            int nearestY = lower_bound(b.begin(), b.end(), cor[i].second) - b.begin();
            if (a[nearestX] == cor[i].first && b[nearestY] == cor[i].second)
                continue;
            if (a[nearestX] == cor[i].first)
                ans += (fy[b[nearestY] - 1] - fy[cor[i].second]);
            else
                ans += (fx[a[nearestX] - 1] - fx[a[nearestX - 1]]);
        }
        cout << ans << endl;
    }

    return 0;
}
