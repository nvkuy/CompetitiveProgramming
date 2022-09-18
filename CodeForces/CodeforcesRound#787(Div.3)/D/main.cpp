#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> p(n + 1), cnt(n + 1, 0), dd(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            cnt[p[i]]++;
            if (p[i] == i)
                p[i] = 0;
        }
        vector<pair<int, int>> t1;
        for (int i = 1; i <= n; i++)
            t1.push_back({cnt[i], i});
        sort(t1.begin(), t1.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            int u = t1[i].second;
            if (dd[u] == 1)
                continue;
            vector<int> t2;
            while (u != 0 && dd[u] == 0) {
                dd[u] = 1;
                t2.push_back(u);
                u = p[u];
            }
            reverse(t2.begin(), t2.end());
            ans.push_back(t2);
        }
        //cout << "ANS: " << endl;
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i].size() << endl;
            for (int j = 0; j < ans[i].size(); j++)
                cout << ans[i][j] << ' ';
            cout << endl;
        }
    }

    return 0;
}
