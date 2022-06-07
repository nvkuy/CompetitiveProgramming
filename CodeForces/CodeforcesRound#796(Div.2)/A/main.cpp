#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, x;
    cin >> t;
    while (t--) {
        cin >> x;
        if (x == 1) {
            cout << "3" << endl;
            continue;
        }
        bitset<33> bs(x);
        int lowBit = 0;
        for (int i = 0; i < 33; i++) {
            if (bs[i] == 1) {
                lowBit = i;
                break;
            }
        }
        if (bs.count() == 1)
            bs[0] = 1;
        for (int i = lowBit + 1; i < 33; i++)
            bs[i] = 0;
        long long ans = 0;
        for (int i = 0; i < 33; i++) {
            if (bs[i] == 1)
                ans += (1LL << i);
        }
        cout << ans << endl;
    }

    return 0;
}
