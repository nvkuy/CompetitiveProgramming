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

int query(int l, int r) {
    if (l == r) return 0;
    cout << "? " << l << ' ' << r << endl;
    cout.flush();
    int rp;
    cin >> rp;
    return rp;
}

int solve(int l, int r) {
    if (l == r) return l;
    int m = (l + r) / 2;
    int p1 = solve(l, m), p2 = solve(m + 1, r);
    int iv1 = query(p1, p2), iv2 = query(p1 + 1, p2);
    if (iv1 - iv2 == p2 - p1)
        return p1;
    return p2;
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
        int max_pos = solve(1, n);
        cout << "! " << max_pos << endl;
        cout.flush();
    }

    return 0;
}
