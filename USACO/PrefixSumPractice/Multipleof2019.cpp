#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;
    int mod = 2019, n = s.length();
    vector<int> p10(s.length() + 1, 1);
    for (int i = 1; i <= n; i++)
        p10[i] = (p10[i - 1] * 10) % mod;
    vector<int> sf(n + 2, 0);
    vector<long long> cnt(mod, 0);
    for (int i = n; i >= 1; i--) {
        sf[i] = sf[i + 1] + p10[n - i] * (s[i - 1] - '0');
        sf[i] %= mod;
        cnt[sf[i]]++;
    }
    cnt[0]++;
    long long ans = 0;
    for (int i = 0; i < mod; i++)
        ans += (cnt[i] * (cnt[i] - 1LL)) / 2LL;
    cout << ans << endl;

    return 0;
}