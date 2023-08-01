#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

bool cmp(const pair<int, int> &p1, const pair<int, int> &p2) {
    if (p1.first == p2.first)
        return p1.second < p2.second;
    return p1.first > p2.first;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<pair<int, int>> mod_a;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            int tmp = a[i] % k;
            if (tmp == 0) tmp = k;
            mod_a.push_back({tmp, i});
        }
        sort(mod_a.begin(), mod_a.end(), cmp);
        for (auto p : mod_a)
            cout << p.second + 1 << ' ';
        cout << endl;
    }

    return 0;
}
