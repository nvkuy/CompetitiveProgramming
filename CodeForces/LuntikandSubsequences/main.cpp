#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, oco, zco, ai;
    cin >> t;
    while (t--) {
        cin >> n;
        oco = zco = 0;
        for (int i = 0; i < n; i++) {
            cin >> ai;
            if (ai == 0)
                zco++;
            if (ai == 1)
                oco++;
        }
        cout << (long long)((1LL << zco) * oco) << endl;
    }

    return 0;
}
