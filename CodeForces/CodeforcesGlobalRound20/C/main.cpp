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
        int i1 = -1, i2 = -1;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n - 1; i++) {
            if (i1 < 0 && a[i] == a[i + 1])
                i1 = i;
            if (a[i] == a[i + 1])
                i2 = i;
        }
        if (i1 < 0 || i1 == i2) {
            cout << "0" << endl;
            continue;
        }
        cout << max(i2 - i1 - 1, 1) << endl;
    }

    return 0;
}
