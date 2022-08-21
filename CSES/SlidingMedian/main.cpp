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

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ordered_set wd;
    for (int i = 0; i < k; i++)
        wd.insert(make_pair(a[i], i));
    auto it = wd.find_by_order((k - 1) / 2);
    cout << (*it).first;
    for (int i = 1; i + k - 1 < n; i++) {
        wd.erase(wd.find({a[i - 1], i - 1}));
        wd.insert({a[i + k - 1], i + k - 1});
        it = wd.find_by_order((k - 1) / 2);
        cout << ' ' << (*it).first;
    }

    return 0;
}
