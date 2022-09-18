#include <bits/stdc++.h>

using namespace std;

int n, a[51];
long long mod = 1e9 + 7;

int gcd(int a1, int a2) {
    return ((a2 == 0) ? a1 : gcd(a2, a1 % a2));
}

int main()
{

    cin >> n;
    cin >> a[0];

    int gcda = a[0];
    long long m = a[0] % mod;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        gcda = gcd(a[i], gcda);
        m = (m * a[i]) % mod;
    }
    long long ans = m;
    for (int i = 1; i < gcda; i++)
        ans = (ans * m) % mod;
    cout << ans;

    return 0;
}
