#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if ((2 * a - b) % 3 == 0 && (2 * a - b) >= 0 && (2 * b - a) % 3 == 0 && (2 * b - a) >= 0) {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }

    return 0;
}
