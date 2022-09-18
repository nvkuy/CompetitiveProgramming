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

    int n, a, b, m;
    cin >> n;
    vector<long long> f(1, 0), pf;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        f[0] += b;
        pf.push_back(a - b);
    }
    sort(pf.begin(), pf.end());
    for (int i = 0; i < n; i++) {
        f.push_back(f.back() + pf.back());
        pf.pop_back();
    }
    //for (int i = 0; i <= n; i++)
    //    cout << f[i] << ' ';
    //cout << endl;
    cin >> m;
    while (m--) {
        cin >> a >> b;
        long long ans = -1;
        //
        cout << ans << endl;
    }

    return 0;
}
