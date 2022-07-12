#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long k, q, l, r;
    cin >> k;
    vector<long long> pre_xor(k + 1, 0);
    for (int i = 1; i <= k; i++) {
        cin >> pre_xor[i];
        pre_xor[i] ^= pre_xor[i - 1];
    }
    pre_xor.push_back(0);
    cin >> q;
    while (q--) {
        cin >> l >> r;
        int rl = l % (k + 1), rr = r % (k + 1);
        if (rl == 0)
            rl += (k + 1);
        if (rr == 0)
            rr += (k + 1);
        if (((l - 1) / (k + 1)) == ((r - 1) / (k + 1))) {
            cout << (pre_xor[rr] ^ pre_xor[rl - 1]) << endl;
            continue;
        }
        cout << ((pre_xor[k + 1] ^ pre_xor[rl - 1]) ^ pre_xor[rr]) << endl;
    }

    return 0;
}
