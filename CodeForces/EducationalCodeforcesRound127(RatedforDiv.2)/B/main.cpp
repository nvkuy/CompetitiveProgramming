#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        vector<bool> dd(n, false);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        bool iok = true;
        for (int i = 1; i < n; i++) {
            if (!iok)
                break;
            if (a[i] - a[i - 1] > 3)
                iok = false;
            if (a[i] - a[i - 1] == 3) {
                if (dd[i - 1])
                    iok = false;
                dd[i] = true;
                a[i - 1]++;
                a[i]--;
                continue;
            }
            if (a[i] - a[i - 1] == 2) {
                if (!dd[i - 1])
                    a[i - 1]++;
                else
                    a[i]--;
                dd[i] = true;
                continue;
            }
            if (a[i] - a[i - 1] == 1) {
                if (dd[i - 1])
                    dd[i] = true;
            }
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
