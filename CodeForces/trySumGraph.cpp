#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

void query1(int x) {
    cout << "+ " << x << endl;
    cout.flush();
    int rp;
    cin >> rp;
}

int query2(int i, int j) {
    cout << "? " << i << ' ' << j << endl;
    cout.flush();
    int rp;
    cin >> rp;
    return rp;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        query1(n + 1);
        query1(n);
        vector<int> tans;
        for (int i = 1; i * 2 <= n; i++) {
            tans.push_back(n - i + 1);
            tans.push_back(i);
        }
        if (n % 2) tans.push_back(n / 2 + 1);
        vector<pair<int, int>> dist_pos;
        for (int i = 2; i <= n; i++) {
            int dist = query2(1, i);
            dist_pos.push_back({dist, i});
        }
        sort(dist_pos.begin(), dist_pos.end());
        int end_point = dist_pos.back().second;
        vector<int> ans1(n + 1), ans2(n + 1);
        ans1[end_point] = tans[0], ans2[end_point] = tans[n - 1];
        for (int i = 1; i <= n; i++) {
            if (i == end_point) continue;
            int dist = query2(end_point, i);
            ans1[i] = tans[dist];
            ans2[i] = tans[n - 1 - dist];
        }
        cout << "! ";
        for (int i = 1; i <= n; i++) cout << ans1[i] << ' ';
        for (int i = 1; i <= n; i++) cout << ans2[i] << ' ';
        cout << endl;
        cout.flush();
        int rp;
        cin >> rp;
        if (rp != 1) break;
    }

    return 0;
}
