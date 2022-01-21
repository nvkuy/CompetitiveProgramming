#include <bits/stdc++.h>

using namespace std;

long long mod = 998244353, a[200002], ans;

int main()
{
    int n;
    cin >> n;
    cin >> a[0];
    ans = a[0];
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        ans = (ans * (a[i] - 1)) % mod;
    }
    cout << ans;

    return 0;
}
