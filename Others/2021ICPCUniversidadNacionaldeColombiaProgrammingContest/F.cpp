#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("in", "r", stdin);

    int n, q, x, y, z, t;
    cin >> n >> q;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    deque<bitset<5005>> col(n, bitset<5005>(0));
    vector<int> row(n, 0);
    deque<int> cnt_col(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            row[i] += (arr[i][j] - '0');
            cnt_col[j] += (arr[i][j] - '0');
            col[i][j] = (arr[j][i] - '0');
        }
    }

    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> x >> y >> z;
            x--, y--;
            if (col[y][x] > z) {
                row[x]--;
                cnt_col[y]--;
            }
            if (col[y][x] < z) {
                row[x]++;
                cnt_col[y]++;
            }
            col[y][x] = z;
        } else {
            cin >> z;
            bitset<5005> tmp(0);
            for (int i = 0; i < n; i++) {
                if (i == 0) {
                    row[i] += z;
                    tmp[i] = z;
                } else {
                    row[i] += col[n - 1][i - 1];
                    tmp[i] = col[n - 1][i - 1];
                }
                row[i] -= col[n - 1][i];
            }
            col.pop_back();
            col.push_front(tmp);
            cnt_col.pop_back();
            cnt_col.push_front(tmp.count());
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (row[i] == n)
                ans++;
            if (cnt_col[i] == n)
                ans++;
            // cout << row[i] << '|' << cnt_col[i] << ' ';
        }
        // cout << endl;
        cout << ans << endl;
    }

    return 0;
}