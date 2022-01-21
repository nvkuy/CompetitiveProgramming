#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    long long a, s, ans;
    long long i;
    cin >> t;
    while (t--) {
        ans = 0;
        cin >> a >> s;
        i = 1;
        while (a > 0) {
            if (s <= 0) {
                ans = -1;
                break;
            }
            if ((a % 10) <= (s % 10)) {
                ans += (i * ((s % 10) - (a % 10)));
                a /= 10; s /= 10; i *= 10;
            } else {
                if ((s < 10) || (((s / 10) % 10) != 1)) {
                    ans = -1;
                    break;
                }
                ans += (i * ((s % 100) - (a % 10)));
                a /= 10; s /= 100; i *= 10;
            }
        }
        if (ans >= 0) {
            while (s > 0) {
                ans += (i * (s % 10));
                i *= 10, s /= 10;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
