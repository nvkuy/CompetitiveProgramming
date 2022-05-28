#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, s, ts;
    cin >> t;
    while (t--) {
        cin >> n;
        s = 0;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s += a[i];
        }
        bool iok = false;
        for (int i = 0; i < n; i++) {
            ts = s - a[i];
            if ((ts % (n - 1)) == 0 && (ts / (n - 1)) == a[i]) {
                iok = true;
                break;
            }
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
