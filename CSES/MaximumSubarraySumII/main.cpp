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

    int n, a, b;
    cin >> n >> a >> b;
    vector<int> arr(n + 1);
    vector<long long> ps1(n + 1, 0);
    set<pair<long long, int>> ps2;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        ps1[i] = ps1[i - 1] + arr[i];
    }
    long long ans = -1e18;
    for (int i = 1; i <= n; i++) {
        if (i - a >= 0)
            ps2.insert(make_pair(ps1[i - a], i - a));
        if (i - b > 0)
            ps2.erase(ps2.find(make_pair(ps1[i - b - 1], i - b - 1)));
        if (ps2.empty())
            continue;
        long long minPs = (*ps2.begin()).first;
        ans = max(ans, ps1[i] - minPs);
    }
    cout << ans;

    return 0;
}
