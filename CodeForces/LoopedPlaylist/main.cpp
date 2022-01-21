#include <bits/stdc++.h>

using namespace std;

int main()
{

    long long n, p, s, a[3000], ans;
    cin >> n >> p;
    s = 0;
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    ans = (long long)(p / s) * n; s = (long long)(p % s);
    if (s == 0) {
        cout << "1 " << ans;
        return 0;
    }
    for (long long i = n; i < (2 * n); i++)
        a[i] = a[i - n];
    long long j = 0, ms = 1e18 + 7, cs = 0, l = -1;
    for (int i = 0; i < (2 * n); i++) {
        if (a[i] >= s) {
            l = i;
            if (i > n)
                l -= n;
            if (i == 0)
                l = n;
            ms = 1;
            break;
        }
        cs += a[i];
        if (cs < s)
            continue;
        while (cs >= s) {
            cs -= a[j];
            j++;
            if (cs < s) {
                j--;
                cs += a[j];
                break;
            }
        }
        if (ms > (i - j + 1)) {
            l = j + 1;
            if (j >= n)
                l -= n;
            ms = i - j + 1;
        }
    }
    cout << l << " " << (long long)(ans + ms);

    return 0;
}
