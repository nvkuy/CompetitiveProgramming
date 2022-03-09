#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t, k, ans;
    cin >> t;
    while (t--) {
        cin >> k;
        int ans = 1;
        while (true) {
            if ((ans % 10 != 3) && (ans % 3 > 0))
                k--;
            if (k <= 0)
                break;
            ans++;
        }
        cout << ans << endl;
    }

    return 0;
}
