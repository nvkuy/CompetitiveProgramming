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

    long long mod = 1e9 + 7;
    string n;
    cin >> n;
    vector<long long> a(n.length() + 1);
    for (int i = 0; i < n.length(); i++)
        a[i + 1] = n[i] - '0';
    vector<long long> f1(a.size(), 0), f2 = f1;
    for (long long i = 1; i < a.size(); i++)
        f1[i] = (f1[i - 1] * 10LL + a[i] * i) % mod;
    for (long long i = 1; i < a.size(); i++)
        f2[i] = (f2[i - 1] * 100LL + 20LL * f1[i - 1] * a[i] + a[i] * a[i] * i) % mod;
    long long ans = 0;
    for (int i = 0; i < a.size(); i++)
        ans = (ans + f2[i]) % mod;
    cout << ans << endl;

    return 0;
}
