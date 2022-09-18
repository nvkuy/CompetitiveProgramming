#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, c;
    cin >> t;
    while (t--) {
        cin >> n >> c;
        vector<int> a(n), f(c + 1, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            f[a[i]]++;
        }
        for (int i = 1; i <= c; i++)
            f[i] += f[i - 1];
        bool iok = true;
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && a[i] == a[i - 1])
                continue;
            for (int j = 1; j * a[i] <= c; j++) {
                if (f[j] > f[j - 1])
                    continue;
                if (f[min((j + 1) * a[i] - 1, c)] - f[j * a[i] - 1] > 0) {
                    iok = false;
                    break;
                }
            }
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
