#include <bits/stdc++.h>

using namespace std;

long long mod = 998244353, pn[200002];

long long binaryExponentiation(long long x,long long n){
    long long result = 1;
    while(n > 0) {
        if(n % 2 == 1)
            result = (result * x) % mod;
        x = (x * x) % mod;
        n = n / 2;
    }
    return result;
}

long long modinv(long long x, long long m) {
    return binaryExponentiation(x, m - 2);
}

int main()
{
    pn[0] = 1;
    for (int i = 1; i <= 200000; i++)
        pn[i] = (pn[i - 1] * i) % mod;
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end(), greater<int>());
        if (a[0] - a[1] > 1) {
            cout << "0\n";
            continue;
        }
        if (a[0] <= a[1]) {
            cout << pn[n] << endl;
            continue;
        }
        int co = 1, i = 1;
        while (i + 1 < n) {
            if (a[i + 1] == a[i]) {
                i++;
                co++;
            } else
                break;
        }
        if (i == n) {
            cout << pn[n] << endl;
            continue;
        }
        long long ans = ((n - 1) * pn[n - 1]) % mod;
        for (int i = co; i < n - 1; i++)
            ans = (ans + mod - (((pn[i] * modinv(pn[i - co], mod) % mod) * pn[n - 1 - co]) % mod)) % mod;

        cout << ans << endl;
    }

    return 0;
}
