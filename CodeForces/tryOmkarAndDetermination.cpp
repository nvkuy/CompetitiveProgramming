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

    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    vector<int> ps(m + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < m; j++) {
            if (i > 0 && j > 0 && a[i - 1][j] == 'X' && a[i][j - 1] == 'X')
                ps[j + 1]++;
        }
    }
    for (int i = 1; i <= m; i++) {
        ps[i] += ps[i - 1];
        // cout << ps[i] << ' ';
    }
    // cout << endl;
    
    int q;
    cin >> q;
    while (q--) {
        int x1, x2;
        cin >> x1 >> x2;
        cout << (ps[x2] - ps[x1] == 0 ? "YES" : "NO") << endl;
    }

    return 0;
}
