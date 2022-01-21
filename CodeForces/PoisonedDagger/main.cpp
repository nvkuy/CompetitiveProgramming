#include <bits/stdc++.h>

using namespace std;

long long a[102], h;
int n;

long long cal(long long k) {
    long long ans = 0;
    for (int i = 1; i < n; i++)
        ans += min(k, a[i] - a[i - 1]);
    return ans + k;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL); cout.tie(NULL);
    int t;
    long long hi, lo, mi, tmp;
    cin >> t;
    while (t--) {
        cin >> n >> h;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        lo = 1, hi = h;
        while (lo <= hi) {
            if (hi == lo)
                break;
            mi = (lo + hi) / 2;
            tmp = cal(mi);
            if (tmp < h)
                lo = mi + 1;
            else if (tmp > h)
                hi = mi;
            else {
                lo = mi;
                break;
            }
        }
        printf("%lld\n", lo);
    }

    return 0;
}
