#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

long long query(int l, int r) {
    cout << "? " << l << ' ' << r << endl;
    cout.flush();
    long long rp;
    cin >> rp;
    return rp;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        long long i, j, k;
        long long total_inv_pair = query(1, n);
        long long l = 1, r = n, m;
        while (l < r) {
            if (r - l == 1) {
                if (query(1, r) == 0)
                    l = r;
                break;
            }
            m = (l + r) / 2;
            long long possible_remain = ((n - m) * (n - m + 1)) / 2LL;
            if (possible_remain < total_inv_pair || query(1, m) > 0)
                r = m - 1;
            else
                l = m;
        }
        i = l;
        //cout << "Found i = " << i << endl;
        //cout.flush();
        long long inv_pair_rm = query(i + 1, n);
        j = (total_inv_pair - inv_pair_rm) + i + 1;
        //cout << "Found j = " << j << endl;
        //cout.flush();
        total_inv_pair -= (((j - i) * (j - i - 1)) / 2LL);
        inv_pair_rm = query(j + 1, n);
        k = (total_inv_pair - inv_pair_rm) + j;
        //cout << "Found k = " << k << endl;
        //cout.flush();
        cout << "! " << i << ' ' << j << ' ' << k << endl;
        cout.flush();
    }

    return 0;
}
