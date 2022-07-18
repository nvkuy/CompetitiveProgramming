#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, x;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        vector<int> a(2 * n);
        for (int i = 0; i < 2 * n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        bool iok = true;
        for (int i = 0; i < n; i++) {
            if (a[i] > a[i + n] - x) {
                iok = false;
                break;
            }
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
