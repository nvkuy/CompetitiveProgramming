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

const int MAXN = 3003;
const long long mod = 1e9 + 7;
long long p2[MAXN];

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    p2[0] = 1;
    for (int i = 1; i < MAXN; i++)
        p2[i] = (p2[i - 1] * 2) % mod;

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int l = n - 1, r = 0;
        for (int j = i - 1; j >= 0; j--) {
            int d = a[i] - a[j];
            while (l - 1 >= 0 && a[j] - a[l - 1] <= d) l--;
            while (r + 1 < n && a[r + 1] - a[i] < d) r++;
            int remain = n - (r - l + 1);
            ans += p2[remain];
            ans %= mod;
        }
    }

    cout << ans << endl;

    return 0;
}