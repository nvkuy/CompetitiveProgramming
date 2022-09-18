#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t, s;
    cin >> t;
    while (t--) {
        cin >> s;
        int ans = 0, cn = 1;
        while (s > 0) {
            ans++;
            s -= cn;
            cn += 2;
        }
        cout << ans << endl;
    }

    return 0;
}
