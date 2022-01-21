#include <bits/stdc++.h>

using namespace std;

long long f[5005][5005];
long long mod = 998244353;

int main()
{
    string s;
    getline(cin, s);
    int n = s.length();
    sort(s.begin(), s.end());
    f[0][0] = 0LL; f[0][1] = 0LL;
    for (int i = 1; i <= n; i++) {
        f[i][0] = 0LL;
        f[0][i] = 0LL;
        f[i][1] = f[i - 1][1];
        if (s[i - 2] != s[i - 1])
            f[i][1]++;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= i; j++) {
            f[i][j] = f[i][j - 1];
            if (s[j - 2] != s[j - 1])
                f[i][j] = (f[i][j] + f[i - 1][j - 1]) % mod;
        }
    }
    long long ans = 0LL;
    for (int i = 1; i <= n; i++)
        ans = (ans + f[n][i]) % mod;
    cout << ans;

    return 0;
}
