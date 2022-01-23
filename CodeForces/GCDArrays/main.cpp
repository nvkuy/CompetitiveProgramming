#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, ans, l, r, k;
    cin >> t;
    while (t--) {
        cin >> l >> r >> k;
        if (r <= 1) {
            cout << "NO" << endl;
            continue;
        }
        if (r - l <= 0) {
            cout << "YES" << endl;
            continue;
        }
        ans = (r - l + 1) / 2;
        if ((l % 2) && (r % 2))
            ans++;
        cout << ((ans <= k) ? "YES" : "NO") << endl;
    }

    return 0;
}
