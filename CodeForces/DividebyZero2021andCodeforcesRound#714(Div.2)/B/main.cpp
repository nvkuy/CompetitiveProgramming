#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, mod = 1e9 + 7;
    vector<long long> permul_count(2e5 + 1);
    permul_count[0] = 1;
    for (long long i = 1; i <= 2e5; i++)
        permul_count[i] = (permul_count[i - 1] * i) % mod;
    int t, ai, num;
    cin >> t;
    while (t--) {
        cin >> n;
        map<int, long long> cnt;
        map<int, long long>::iterator it;
        for (int i = 0; i < n; i++) {
            cin >> ai;
            cnt[ai]++;
        }
        num = ai;
        for (it = cnt.begin(); it != cnt.end(); it++)
            num &= (*it).first;
        long long ans = (cnt[num] * (cnt[num] - 1)) % mod;
        ans = (ans * permul_count[n - 2]) % mod;
        cout << ans << endl;
    }

    return 0;
}
