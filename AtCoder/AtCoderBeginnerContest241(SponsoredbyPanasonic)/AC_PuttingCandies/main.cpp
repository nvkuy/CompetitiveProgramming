#include <bits/stdc++.h>

using namespace std;

long long a[200002];

int main()
{

    long long n, k, ans = 0LL, s = 0LL, co = 0LL;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    co = 1LL, ans = a[ans], s = ans;
    while (ans % n != 0) {
        co++;
        s += a[ans % n];
        ans += a[ans % n];
    }
    ans = (s * (k / co));
    k = k % co;
    while (k--)
        ans += a[ans % n];
    cout << ans;

    return 0;
}
