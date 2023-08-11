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

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int> col(m, 0), row(m, 0);
        int good_col = 0, preOne = -1e9;
        for (int i = 0; i < n * m; i++) {
            if (s[i] == '1') {
                if (col[i % m] == 0)
                    good_col++;
                col[i % m]++;
                preOne = i;
            }
            int good_row = row[i % m];
            if (i - preOne < m)
                good_row++;
            row[i % m] = good_row;
            cout << good_col + good_row << ' ';
        }
        cout << endl;
    }

    return 0;
}
