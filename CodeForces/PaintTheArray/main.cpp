#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main()
{
    int t, n;
    long long gcd1, gcd2, a[102];
    cin >> t;
    while (t--) {
        cin >> n;
        //memset(a, 0, sizeof(a));
        gcd1 = -1, gcd2 = -1;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i % 2 > 0) {
                if (gcd1 < 0)
                    gcd1 = a[i];
                else
                    gcd1 = gcd(gcd1, a[i]);
            } else {
                if (gcd2 < 0)
                    gcd2 = a[i];
                else
                    gcd2 = gcd(gcd2, a[i]);
            }
        }
        //cout << gcd1 << "|" << gcd2 << endl;
        bool isOk = true;
        for (int i = 0; i < n; i += 2) {
            if (a[i] % gcd1 == 0) {
                isOk = false;
                break;
            }
        }
        if (isOk) {
            cout << gcd1 << endl;
            continue;
        }
        isOk = true;
        for (int i = 1; i < n; i += 2) {
            if (a[i] % gcd2 == 0) {
                isOk = false;
                break;
            }
        }
        if (isOk) {
            cout << gcd2 << endl;
            continue;
        }
        cout << "0" << endl;
        /*
        for (long long i = 2; i <= gcd1; i++) {
            if (gcd1 % i > 0)
                continue;
            isOk = true;
            for (int j = 0; j < n; j += 2) {
                if (a[j] % i == 0) {
                    isOk = false;
                    break;
                }
            }
            if (isOk) {
                ans = i;
                break;
            }
        }
        if (ans > 0) {
            cout << ans << endl;
            continue;
        }
        for (long long i = 2; i <= gcd2; i++) {
            if (gcd2 % i > 0)
                continue;
            isOk = true;
            for (int j = 1; j < n; j += 2) {
                if (a[j] % i == 0) {
                    isOk = false;
                    break;
                }
            }
            if (isOk) {
                ans = i;
                break;
            }
        }
        cout << ans << endl;
        */
    }

    return 0;
}
