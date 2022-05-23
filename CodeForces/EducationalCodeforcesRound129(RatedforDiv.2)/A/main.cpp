#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, ai, m;
    cin >> t;
    while (t--) {
        int am = 0, bm = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ai;
            am = max(am, ai);
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> ai;
            bm = max(bm, ai);
        }
        if (am > bm)
            cout << "Alice\nAlice";
        else if (am < bm)
            cout << "Bob\nBob";
        else
            cout << "Alice\nBob";
        cout << endl;
    }

    return 0;
}
