#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, l, r, c;
    cin >> t;
    while (t--) {
        cin >> n;
        int minL = 1e9 + 7, minR = 1e9 + 7, bestL = 1e9 + 7, bestR = 0, ans = 1e9 + 7, ansL = 1e9 + 7, ansR = 0;
        for (int i = 0; i < n; i++) {
            cin >> l >> r >> c;
            if (l < bestL) {
                bestL = l;
                minL = c;
            }
            if (l == bestL)
                minL = min(minL, c);
            if (r > bestR) {
                bestR = r;
                minR = c;
            }
            if (r == bestR)
                minR = min(minR, c);
            if (l <= ansL && r >= ansR) {
                if (l < ansL || r > ansR) {
                    ans = c;
                    ansL = l;
                    ansR = r;
                } else
                    ans = min(ans, c);
            }
            if (bestL < ansL || bestR > ansR) {
                ans = minL + minR;
                ansL = bestL;
                ansR = bestR;
            } else
                ans = min(ans, minL + minR);
            cout << ans << endl;
        }
    }

    return 0;
}
