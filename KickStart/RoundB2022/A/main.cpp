#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cout << fixed << setprecision(13);
    long long tt, r, a, b;
    cin >> tt;
    for (int t = 1; t <= tt; t++) {
        cin >> r >> a >> b;
        long double ans = 0;
        while (r > 0) {
            //cout << r << endl;
            ans += (r * r * M_PI);
            r *= a;
            //cout << ans << endl;
            ans += (r * r * M_PI);
            r /= b;
            //cout << ans << endl;
        }
        cout << "CASE #" << t << ": " << ans << endl;
    }

    return 0;
}
