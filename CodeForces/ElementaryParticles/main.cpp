#include <bits/stdc++.h>

using namespace std;

int dd[150051];

int main()
{
    int t, n, ai, ans, ml, mr;
    cin >> t;
    while (t--) {
        cin >> n;
        memset(dd, -1, sizeof(dd));
        ans = -1e9 - 7;
        for (int i = 0; i < n; i++) {
            cin >> ai;
            if (dd[ai] == -1)
                dd[ai] = i;
            else {
                ml = dd[ai];
                mr = n - i - 1;
                ans = max(ans, ml + mr + 1);
                dd[ai] = i;
                //cout << "TEST: " << ml << ' ' << mr << endl;
            }
        }
        if (ans < 0) {
            cout << "-1\n";
            continue;
        }
        cout << ans << endl;
    }

    return 0;
}
