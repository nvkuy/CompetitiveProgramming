#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, l, r, ai, ans, p2;
    cin >> t;
    while (t--) {
        cin >> l >> r;
        vector<int> initBitCnt(22, 0), finalBitCnt(22, 0);
        for (int i = l; i <= r; i++) {
            cin >> ai;
            bitset<22> bs1(i), bs2(ai);
            for (int j = 0; j < 22; j++) {
                initBitCnt[j] += bs1[j];
                finalBitCnt[j] += bs2[j];
            }
        }
        ans = 0, p2 = 1;
        for (int i = 0; i < 22; i++) {
            if (initBitCnt[i] != finalBitCnt[i])
                ans += p2;
            p2 *= 2;
        }
        cout << ans << endl;
    }

    return 0;
}
