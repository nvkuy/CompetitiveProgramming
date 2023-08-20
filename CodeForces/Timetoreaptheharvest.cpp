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

    long long n;
    cin >> n;
    vector<long long> a(n + 1, 0), ps(n + 1, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; i++)
        ps[i] = ps[i - 1] + a[i];

    int k;
    cin >> k;
    while (k--) {
        int l;
        cin >> l;
        long long p = upper_bound(a.begin(), a.end(), l) - a.begin();
        // cout << "@p: " << p << ' ' << ps[p - 1] << endl;
        cout << ps[n] - ps[p - 1] - (n - p + 1) * l << endl; 
    }

    return 0;
}
