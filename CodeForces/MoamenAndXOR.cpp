#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MAXN = 2e5, mod = 1e9 + 7;
int per[MAXN + 1], p2[MAXN + 1];

int power(int num, int pow) {
    if (pow == 0) return 1;
    if (pow & 1) return (1LL * num * power(num, pow ^ 1)) % mod;
    return power((1LL * num * num) % mod, pow >> 1);
}

int ckn(int n, int k) {
    return (1LL * per[n] * power((1LL * per[n - k] * per[k]) % mod, mod - 2)) % mod;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    per[0] = p2[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        per[i] = (1LL * per[i - 1] * i) % mod;
        p2[i] = ((1LL * p2[i - 1]) << 1) % mod;
    }

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int ans = 0, equal_cnt = 0;
        for (int show_time = 0; show_time < n; show_time += 2) {
            equal_cnt += ckn(n, show_time);
            equal_cnt %= mod;
        }
        if (n & 1) {
            equal_cnt++;
            equal_cnt %= mod;
        }
        ans = power(equal_cnt, k);
        if (!(n & 1)) {
            for (int bit = 0; bit < k; bit++) {
                int num_higher_bit = k - bit - 1, num_lower_bit = bit;
                ans += (1LL * power(equal_cnt, num_higher_bit) * power(p2[bit], n)) % mod;
                ans %= mod;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
