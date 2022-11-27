#include <bits/stdc++.h>
using namespace std;

const int max_n = 1e4, mod = 1e9 + 7, max_d = 100;
int f[max_n + 1][max_d + 1];

int main() {

    string s;
    int d, n;
    cin >> s;
    cin >> d;
    n = s.length();
    f[0][0] = 1; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            for (int k = 0; k <= 9; k++) {
                f[i + 1][(j + k) % d] += f[i][j];
                f[i + 1][(j + k) % d] %= mod;
            }
        }
    }
    // for (int i = 0; i <= n; i++)
    //     cout << f[i][0] << endl;
    reverse(s.begin(), s.end());
    int ans = 0, carry = 0; // carry: sum prefix
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < s[i - 1] - '0'; j++) {
            ans += f[i - 1][(d - ((j + carry) % d)) % d];
            ans %= mod;
        }
        carry += (s[i - 1] - '0');
        carry %= d;
    }
    if (carry == 0) ans = (ans + 1) % mod; // if number is multibly of d
    if (--ans < 0) ans += mod; // not count 0
    cout << ans << endl;

    return 0;
}