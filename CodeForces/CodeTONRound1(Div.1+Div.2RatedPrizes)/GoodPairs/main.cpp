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
        int imax = 0, imin = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] > a[imax])
                imax = i;
            if (a[i] < a[imin])
                imin = i;
        }
        cout << imax + 1 << ' ' << imin + 1 << endl;
    }

    return 0;
}
