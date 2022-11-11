#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    a.push_back(0);
    sort(a.begin(), a.end());
    int max_d = 0, min_d = 1e9 + 7;
    for (int i = 0; i < a.size(); i++) {
        if (i + 1 < a.size())
            max_d = max(max_d, a[i + 1] - a[i]);
        if (i + 2 < a.size())
            min_d = min(min_d, a[i + 2] - a[i]);
    }
    if (max_d >= min_d)
        cout << 0 << endl;
    else
        cout << max_d << endl;

    return 0;
}
