#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int ans = 0;
        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                int tmp = r - l + 1;
                for (int i = l; i <= r; i++)
                    if (a[i] == 0)
                        tmp++;
                ans += tmp;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
