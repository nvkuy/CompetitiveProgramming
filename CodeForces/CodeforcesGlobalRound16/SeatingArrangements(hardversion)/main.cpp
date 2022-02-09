#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> a;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first == p2.first)
        return p1.second > p2.second;
    return p1.first < p2.first;
}

int main()
{
    int t, n, m, ai;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        a.clear();
        for (int i = 0; i < m; i++) {
            cin >> ai;
            a.push_back(make_pair(ai, i));
        }
        sort(a.begin(), a.end(), cmp);
        for (int i = 0; i < m; i++) {
            a[i].first = i;
            swap(a[i].first, a[i].second);
        }
        sort(a.begin(), a.end());
        vector<bool> dd(m, false);
        int ans = 0, co;
        for (int i = 0; i < m; i++) {
            co = 0;
            for (int j = 0; j < a[i].second; j++)
                co += dd[j];
            ans += co;
            dd[a[i].second] = true;
        }
        cout << ans << endl;
    }

    return 0;
}
