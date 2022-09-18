#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t, n, ans;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        ans = 1e9;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int c1 = 0; c1 <= 101; c1++) {
            if (c1 > ans)
                break;
            for (int c2 = 0; c2 <= 101; c2++) {
                if (c1 + c2 > ans)
                    break;
                int c3 = 0, cc3;
                for (int i = 0; i < n; i++) {
                    int rm = a[i], rc1 = c1, rc2 = c2;
                    if (rm % 3 == 1) {
                        if (rm == 1 || rc2 - 2 < rc1) {
                            rc1--;
                            rm--;
                        } else {
                            rc2 -= 2;
                            rm -= 4;
                        }
                    }
                    if (rm % 3 == 2) {
                        if (rc1 - 2 < rc2)
                            rc2--;
                        else
                            rc1 -= 2;
                        rm -= 2;
                    }
                    if (rc1 < 0 || rc2 < 0) {
                        c3 = -1;
                        break;
                    }
                    cc3 = min(rc1, rc2);
                    rm -= cc3 * 3;
                    c3 = max(c3, rm / 3);
                }
                if (c1 + c2 + c3 > ans)
                    break;
                if (c3 != -1)
                    ans = min(ans, c1 + c2 + c3);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
