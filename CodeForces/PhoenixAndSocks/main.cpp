#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

int main()
{
    int t, n, l, r, ans, tmp;
    cin >> t;
    while (t--) {
        cin >> n >> l >> r;
        vector<int> co(n + 1, 0);
        for (int i = 0; i < l; i++) {
            cin >> tmp;
            co[tmp]++;
        }
        for (int i = 0; i < r; i++) {
            cin >> tmp;
            co[tmp]--;
        }
        int p1 = 0, p2 = 0, l = 0, r = 0;
        for (int i = 0; i <= n; i++) {
            if (co[i] > 0) {
                l += co[i];
                p1 += (co[i] / 2);
            } else {
                r -= co[i];
                p2 -= (co[i] / 2);
            }
        }
        if (l == r)
            ans = l;
        else if (l > r) {
            ans = r;
            p2 = (l - r) / 2;
            if (p1 >= p2)
                ans += p2;
            else {
                ans += p1;
                p2 -= p1;
                ans += (2 * p2);
            }
        } else {
            ans = l;
            p1 = (r - l) / 2;
            if (p1 <= p2)
                ans += p1;
            else {
                ans += p2;
                p1 -= p2;
                ans += (2 * p1);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
