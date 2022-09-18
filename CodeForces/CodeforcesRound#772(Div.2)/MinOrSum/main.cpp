#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, ans, ai;
    cin >> t;
    while (t--) {
        cin >> n;
        ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> ai;
            ans |= ai;
        }
        cout << ans << endl;
    }

    return 0;
}
