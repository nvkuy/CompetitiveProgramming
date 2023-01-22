#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> gcd_pf(n + 1, 0), gcd_sf(n + 2, 0);
    for (int i = 1; i <= n; i++)
        gcd_pf[i] = gcd(gcd_pf[i - 1], a[i]);
    for (int i = n; i >= 1; i--)
        gcd_sf[i] = gcd(gcd_sf[i + 1], a[i]);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, gcd(gcd_pf[i - 1], gcd_sf[i + 1]));
    cout << ans << endl;

    return 0;
}