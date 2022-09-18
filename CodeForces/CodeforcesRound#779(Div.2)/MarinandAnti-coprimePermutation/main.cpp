#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

long long per[1001], mod = 998244353;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    per[0] = 1;
    for (int i = 1; i <= 1e3; i++)
        per[i] = (per[i - 1] * i) % mod;

    int t;
    long long n;
    cin >> t;
    while (t--) {
        cin >> n;
        if (n % 2) {
            cout << "0\n";
            continue;
        }
        cout << (per[n / 2] * per[n / 2]) % mod << endl;
    }

    return 0;
}
