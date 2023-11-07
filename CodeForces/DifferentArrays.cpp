#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)
#define low_bit(x) __builtin_ctzll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const long long mod = 998244353;
const int ZERO = 333 * 333 - 1, MAX_VAL = 333 * 333 * 2;
long long pf[MAX_VAL + 1][2], f[MAX_VAL + 1][2];

void copyF() {
    for (int i = 0; i <= MAX_VAL; i++)
        for (int j = 0; j < 2; j++)
            pf[i][j] = f[i][j];
}

void clearF() {
    for (int i = 0; i <= MAX_VAL; i++)
        for (int j = 0; j < 2; j++)
            f[i][j] = 0;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    f[a[1] + ZERO][0] = f[a[1] + ZERO][1] = 1;
    copyF();
    for (int i = 2; i + 1 < n; i++) {
        clearF();
        f[a[i] + ZERO][0] = f[a[i] + ZERO][1] = pf[ZERO][0];
        for (int j = 0; j <= MAX_VAL; j++) {
            if (j == ZERO) continue;
            int val = a[i] + j;
            if (val >= 0 && val <= MAX_VAL) {
                f[val][0] += pf[j][1];
                f[val][1] += pf[j][1];
                f[val][0] %= mod;
                f[val][1] %= mod;
            }
            val = 2 * ZERO + a[i] - j;
            if (val >= 0 && val <= MAX_VAL) {
                f[val][0] += pf[j][0];
                f[val][1] += pf[j][0];
                f[val][0] %= mod;
                f[val][1] %= mod;
            }
        }
        copyF();
    }
    long long ans = f[ZERO][0];
    for (int i = 0; i <= MAX_VAL; i++) {
        if (i == ZERO) continue;
        ans += f[i][0] + f[i][1];
        ans %= mod;
    }
    cout << ans << endl;

    return 0;
}
