#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, oc;
    cin >> t;
    while (t--) {
        cin >> n;
        oc = 0;
        bool iok = true;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 1)
                oc++;
        }
        if (oc != 1)
            iok = false;
        for (int i = 0; i < n; i++) {
            if (a[(i + 1) % n] - a[i] > 1) {
                iok = false;
                break;
            }
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
