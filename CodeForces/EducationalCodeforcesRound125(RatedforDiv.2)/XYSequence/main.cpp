#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long t, n, b, x, y, ans;
    cin >> t;
    while (t--) {
        vector<long long> a(1, 0);
        cin >> n >> b >> x >> y;
        ans = 0LL;
        for (int i = 0; i < n; i++) {
            if (a.back() + x > b)
                a.push_back(a.back() - y);
            else
                a.push_back(a.back() + x);
            ans += a.back();
        }
        cout << ans << endl;
    }

    return 0;
}
