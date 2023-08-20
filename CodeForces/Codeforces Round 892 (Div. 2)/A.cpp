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

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b, c;
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        b.push_back(a[0]);
        for (int i = 1; i < n; i++) {
            if (a[i] == b.back())
                b.push_back(a[i]);
            else
                c.push_back(a[i]);
        }
        if (a.size() == b.size()) {
            cout << -1 << endl;
            continue;
        }
        cout << b.size() << ' ' << c.size() << endl;
        for (int num : b) cout << num << ' ';
        cout << endl;
        for (int num : c) cout << num << ' ';
        cout << endl;
    }

    return 0;
}
