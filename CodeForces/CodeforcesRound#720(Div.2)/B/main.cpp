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
        int pmin = 0;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[pmin] > a[i])
                pmin = i;
        }
        cout << n - 1 << endl;
        int nai = a[pmin] + 1;
        for (int i = pmin + 1; i < n; i++) {
            cout << pmin + 1 << ' ' << i + 1 << ' ' << a[pmin] << ' ' << nai << endl;
            nai++;
        }
        nai = a[pmin] + 1;
        for (int i = pmin - 1; i >= 0; i--) {
            cout << pmin + 1 << ' ' << i + 1 << ' ' << a[pmin] << ' ' << nai << endl;
            nai++;
        }
    }

    return 0;
}
