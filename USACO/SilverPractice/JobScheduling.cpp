#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, d, m;
    cin >> n >> d >> m;
    vector<vector<int>> job(n + 1);
    for (int i = 1; i <= m; i++) {
        int start;
        cin >> start;
        job[start].push_back(i);
    }

    vector<vector<int>> ans;
    int ll = 0, rr = m;
    while (ll < rr) {
        int mm = (ll + rr) / 2;
        vector<vector<int>> tans(n + 1);
        queue<pair<int, int>> in_process;
        for (int i = 1; i <= n; i++) {
            for (int j : job[i])
                in_process.push({j, i + d});
            for (int j = 0; j < mm; j++) {
                if (in_process.size() == 0) break;
                auto tmp = in_process.front();
                if (tmp.second < i) break;
                tans[i].push_back(tmp.first);
                in_process.pop();
            }
        }
        if (in_process.size() > 0)
            ll = mm + 1;
        else {
            rr = mm;
            ans = tans;
        }
    }

    cout << rr << endl;
    for (int i = 1; i <= n; i++) {
        for (int j : ans[i])
            cout << j << ' ';
        cout << 0 << endl;
    }

    return 0;
}
