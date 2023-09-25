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
        vector<int> pos(4 * n + 4, - 1);
        int d = query2(1, 2), p1 = n, p2 = p1 + d;
        pos[p1] = 1, pos[p2] = 2;
        for (int i = 3; i <= n; i++) {
            int d1 = query2(1, i);
            int d2 = query2(2, i);
            if (d1 + d2 == d) pos[p1 + d1] = i;
            else {
                if (d1 < d2)
                    pos[p1 - d1] = i;
                else
                    pos[p2 + d2] = i;
            }
        }
        vector<int> pos1, pos2;
        for (int i = 0; i <= 4 * n; i++)
            if (pos[i] != -1) pos1.push_back(pos[i]);
        assert(pos1.size() == n);
        pos2 = pos1;
        reverse(pos2.begin(), pos2.end());
        vector<int> ans1(n + 1), ans2(n + 1);
        for (int i = 0; i < n; i++) {
            ans1[pos1[i]] = tans[i];
            ans2[pos2[i]] = tans[i];
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
