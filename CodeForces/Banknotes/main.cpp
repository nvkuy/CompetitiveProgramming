#include <bits/stdc++.h>

using namespace std;

int main()
{

    long long t, n, k, a[11], ai, i, cs;
    long long ans;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (i = 0; i < n; i++) {
            cin >> ai;
            a[i] = pow(10, ai);
        }
        ans = 0, i = 0; k++;
        while (k > 0) {
            cs = 9;
            if (i < n) {
                while ((cs + 1) < (a[i + 1] / a[i])) {
                    cs *= 10;
                    cs += 9;
                }
            } else {
                ans += (k * a[i - 1]);
                break;
            }
            if (k < cs) {
                ans += (k * a[i]);
                break;
            }
            ans += (cs * a[i]);
            k -= cs;
            i++;
            //cout << cs << "|" << k << endl;
        }
        cout << ans << endl;
    }

    return 0;
}
