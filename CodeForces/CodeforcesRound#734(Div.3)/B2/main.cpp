#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, k, ai;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> ans(n, 0);
        vector<vector<int>> pos(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> ai;
            pos[ai].push_back(i);
        }
        vector<int> rm;
        for (int i = 1; i <= n; i++) {
            if (pos[i].size() >= k) {
                for (int j = 0; j < k; j++)
                    ans[pos[i][j]] = j + 1;
                continue;
            }
            for (int j = 0; j < pos[i].size(); j++)
                rm.push_back(pos[i][j]);
        }
        for (int i = 0; i + k <= rm.size(); i += k)
            for (int j = 0; j < k; j++)
                ans[rm[i + j]] = j + 1;
        for (int i = 0; i < n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }

    return 0;
}
