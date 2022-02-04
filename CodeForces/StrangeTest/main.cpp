#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, a, b, ans;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        ans = b - a;
        ans = min(ans, 1 + (a | b) - b);
        for (int i = a; i <= b; i++) {
            if ((i | b) == b) {
                ans = min(ans, i - a + 1);
                break;
            }
        }
        for (int i = b; i <= b + a; i++) {
            if ((i | a) == i) {
                ans = min(ans, i - b + 1);
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
