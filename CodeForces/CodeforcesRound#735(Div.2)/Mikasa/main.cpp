#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, m, rs;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        if (n > m) {
            cout << "0\n";
            continue;
        }
        bitset<30> bsn(n), bsm(m), ans(0);
        bool isa = false;
        int p = -1;
        for (int i = 29; i >= 0; i--) {
            if (bsn[i] > bsm[i]) {
                isa = true;
                break;
            }
            if (bsm[i] == false && pow(2, i) <= n)
                p = i;
            if (bsn[i] != bsm[i])
                ans[i] = bsm[i];
        }
        if (!isa) {
            if (p == -1)
                ans = bitset<30>(m + 1);
            else {
                for (int i = 0; i < p; i++)
                    ans[i] = false;
                ans[p] = true;
            }
        }
        rs = 0;
        for (int i = 0; i < 30; i++)
            rs += (pow(2, i) * ans[i]);
        cout << rs << endl;
    }

    return 0;
}
