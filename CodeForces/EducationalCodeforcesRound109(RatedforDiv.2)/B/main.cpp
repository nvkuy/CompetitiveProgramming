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
        bool is = true;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] - i != 1)
                is = false;
        }
        if (is) {
            cout << "0" << endl;
            continue;
        }
        if (a[0] == 1 || a[n - 1] == n) {
            cout << "1" << endl;
            continue;
        }
        if (a[0] == n && a[n - 1] == 1) {
            cout << "3" << endl;
            continue;
        }
        cout << "2" << endl;
    }

    return 0;
}
