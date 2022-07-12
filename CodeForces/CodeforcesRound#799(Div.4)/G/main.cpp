#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int i = 0, ans = 0;
        while (i + k < n) {
            bool isIok = true;
            int j = i + 1;
            for (; j < i + k; j++) {
                if (a[j] * 2 <= a[j - 1]) {
                    isIok = false;
                    break;
                }
            }
            if (!isIok) {
                i = j;
                continue;
            }
            i += k;
            while (i < n && a[i] * 2 > a[i - 1]) {
                ans++;
                i++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
