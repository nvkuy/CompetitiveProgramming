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

const long long mod = 1e9 + 7;
const int MAXN = 3003;
long long pss[MAXN][MAXN][2], psw[MAXN][MAXN][2];

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<long long> a(n + 1, -1e18);
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            pss[i][j][1] = pss[i][j][0] = psw[i][j][1] = psw[i][j][0] = 0;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = 0;
        for (int j = 1; j < i; j++) {
            pss[i][j][1]++;
            psw[i][j][1]++;
            while (a[i] - a[j] < a[j] - a[l + 1]) l++;
            pss[i][j][1] += pss[j][l][1] + pss[j][l][0] + psw[j][l][0];
            pss[i][j][0] += (pss[j][n][0] - pss[j][l][0] + mod) + (pss[j][n][1] - pss[j][l][1] + mod);
            psw[i][j][1] += psw[j][l][0] + psw[j][l][1];
            psw[i][j][0] += (psw[j][n][0] - psw[j][l][0] + mod) + (psw[j][n][1] - psw[j][l][1] + mod);
            pss[i][j][1] %= mod;
            pss[i][j][0] %= mod;
            psw[i][j][1] %= mod;
            psw[i][j][0] %= mod;
        }
        for (int j = 1; j <= n; j++) {
            pss[i][j][1] += pss[i][j - 1][1];
            pss[i][j][0] += pss[i][j - 1][0];
            psw[i][j][1] += psw[i][j - 1][1];
            psw[i][j][0] += psw[i][j - 1][0];
            pss[i][j][1] %= mod;
            pss[i][j][0] %= mod;
            psw[i][j][1] %= mod;
            psw[i][j][0] %= mod;
        }
        ans += pss[i][n][1] + pss[i][n][0];
        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}