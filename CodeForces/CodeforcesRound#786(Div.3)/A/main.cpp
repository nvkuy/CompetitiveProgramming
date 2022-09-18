#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, x, y;
    cin >> t;
    while (t--) {
        cin >> x >> y;
        if (y % x > 0) {
            cout << "0 0" << endl;
            continue;
        }
        cout << "1 " << y / x << endl;
    }

    return 0;
}
