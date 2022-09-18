#include <bits/stdc++.h>

using namespace std;

int a[200002], ddx[200002], ddd[200002];
string s;

int main()
{
    int t, n, l, r;
    cin >> t;
    while (t--) {
        cin >> n;
        memset(ddd, 0, sizeof(ddd));
        memset(ddx, 0, sizeof(ddx));
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        cin.ignore();
        getline(cin, s);
        bool ip = true;
        for (int i = 1; i <= n; i++) {
            if (a[i] < 1 || a[i] > n) {
                if (!ip)
                    break;
                if (s[i - 1] == 'B' && a[i] < 1)
                    ip = false;
                if (s[i - 1] == 'R' && a[i] > n)
                    ip = false;
                continue;
            }
            if (s[i - 1] == 'R')
                ddd[a[i]]++;
            else
                ddx[a[i]]++;
        }
        if (!ip) {
            cout << "NO\n";
            continue;
        }
        l = 0, r = 0;
        for (int i = 1; i <= n; i++) {
            l++; r++;
            if (ddd[n - i + 1] > r || ddx[i] > l) {
                ip = false;
                break;
            }
            l -= ddx[i];
            r -= ddd[n - i + 1];
        }
        cout << (ip ? "YES\n" : "NO\n");
    }

    return 0;
}
