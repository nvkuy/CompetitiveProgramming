#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int32_t main()
{

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        int ans = 2e18;
        cin >> a >> b;
        for (int i = 0; i <= 64 * 2; i++) {
            for (int j = 0; j <= i; j++) {
                int tans = 0, ta = a, tb = b;
                for (int k = 0; k < j; k++) {
                    if (ta & 1) {
                        tans++;
                        ta++;
                    }
                    ta /= 2;
                    tans++;
                }
                for (int k = 0; k < i - j; k++) {
                    if (tb & 1) {
                        tans++;
                        tb--;
                    }
                    tb /= 2;
                    tans++;
                }
                tans += (tb - ta);
                if (tb >= ta)
                    ans = min(ans, tans);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
