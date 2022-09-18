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
        set<int> dd;
        bool hasOne = false, hasZero = false, hasTwo = false;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 1)
                hasOne = true;
            if (a[i] == 2)
                hasTwo = true;
            if (a[i] == 0)
                hasZero = true;
            dd.insert(a[i]);
        }
        if ((hasOne & hasZero) || (hasOne & hasTwo)) {
            cout << "NO" << endl;;
            continue;
        }
        bool iok = true;
        if (hasOne) {
            for (int i = 0; i < n; i++) {
                if (dd.find(a[i] - 1) != dd.end()) {
                    iok = false;
                    break;
                }
            }
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
