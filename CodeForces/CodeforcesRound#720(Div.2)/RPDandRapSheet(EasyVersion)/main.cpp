#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int query(int y) {
    cout << y << endl;
    cout.flush();
    int rp;
    cin >> rp;
    return rp;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            int rp = query(tmp ^ i);
            tmp ^= (tmp ^ i);
            if (rp == -1)
                return 0;
            if (rp == 1)
                break;
        }
    }

    return 0;
}
