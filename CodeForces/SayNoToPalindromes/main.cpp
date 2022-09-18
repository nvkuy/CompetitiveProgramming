#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

string s;
int n, m, f[6][200002];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    cin.ignore();
    getline(cin, s);
    for (int i = 0; i < 6; i++)
        f[i][0] = 0;
    for (int c = 0; c < 3; c++) {
        int cc1 = c, cc2 = c;
        for (int i = 1; i <= n; i++) {
            f[c][i] = f[c][i - 1];
            f[c + 3][i] = f[c + 3][i - 1];
            if (s[i - 1] - 'a' != cc1)
                f[c][i]++;
            if (s[i - 1] - 'a' != cc2)
                f[c + 3][i]++;
            cc1 = (cc1 + 1) % 3;
            cc2 = (cc2 + 2) % 3;
        }
    }
    int l, r, ans;
    while (m--) {
        cin >> l >> r;
        ans = 1e9;
        for (int c = 0; c < 6; c++)
            ans = min(ans, f[c][r] - f[c][l - 1]);
        cout << ans << endl;
    }

    return 0;
}
