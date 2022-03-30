#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    long long x, y, me, ans;
    cin >> t;
    while (t--) {
        cin >> y >> x;
        me = max(x, y);
        ans = (me - 1) * (me - 1);
        if (me % 2) {
            ans += x;
            ans += (me - y);
        } else {
            ans += y;
            ans += (me - x);
        }
        cout << ans << endl;
    }

    return 0;
}
