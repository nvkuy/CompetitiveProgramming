#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, ans;
    cin >> t;
    while (t--) {
        cin >> n;
        bitset<33> tmp(n);
        for (int i = 32; i >= 0; i--) {
            if (tmp[i]) {
                ans = (1 << i) - 1;
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
