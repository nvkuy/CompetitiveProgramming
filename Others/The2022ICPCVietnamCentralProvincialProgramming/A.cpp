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

int f[303][303][303], ps[303];
int n, k;
string s;

int cal(int l, int r, int nb1) {
    if (f[l][r][nb1] != -1)
        return f[l][r][nb1];
    if (nb1 >= k)
        return 0;
    if ((ps[n] - ps[r] + ps[l - 1] - nb1) >= k)
        return 1;
    f[l][r][nb1] = max(min(cal(l + 1, r - 1, nb1 + (s[l - 1] == 'B')), cal(l + 2, r, nb1 + (s[l - 1] == 'B'))), f[l][r][nb1]);
    f[l][r][nb1] = max(min(cal(l + 1, r - 1, nb1 + (s[r - 1] == 'B')), cal(l, r - 2, nb1 + (s[r - 1] == 'B'))), f[l][r][nb1]);
    return f[l][r][nb1];
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    cin >> n >> k;
    cin >> s;
    for (int i = 0; i <= n; i++) {
        ps[i] = 0;
        for (int j = 0; j <= n; j++)
            for (int k = 0; k <= n; k++)
                f[i][j][k] = -1;
    }
    for (int i = 1; i <= n; i++)
        ps[i] = ps[i - 1] + (s[i - 1] == 'B');
    cout << ((cal(1, n, 0) == 1) ? "YES" : "NO") << endl;

    return 0;
}
