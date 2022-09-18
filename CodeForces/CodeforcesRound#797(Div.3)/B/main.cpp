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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        bool iok = true;
        int delta = 0;
        for (int i = 0; i < n; i++)
            delta = max(delta, a[i] - b[i]);
        for (int i = 0; i < n; i++) {
            if (max(a[i] - delta, 0) == b[i])
                continue;
            iok = false;
            break;
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
