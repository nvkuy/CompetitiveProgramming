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
        vector<int> b(n), a;
        for (int i = 0; i < n; i++) cin >> b[i];
        a.push_back(b[0]);
        for (int i = 1; i < n; i++) {
            if (b[i] < b[i - 1]) a.push_back(b[i]);
            a.push_back(b[i]);
        }
        cout << a.size() << endl;
        for (int num : a) cout << num << ' ';
        cout << endl;
    }

    return 0;
}
