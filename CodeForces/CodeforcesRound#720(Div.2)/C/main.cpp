#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int query(int t, int i, int j, int x) {
    cout << "? " << t << ' ' << i + 1 << ' ' << j + 1 << ' ' << x << endl;
    cout.flush();
    int rp;
    cin >> rp;
    return rp;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> ans(n, 0);
        int i = 0, p = -1;
        while (i + 1 < n) {
            int tmp = query(1, i, i + 1, n - 1);
            if (tmp < 0)
                return 0;
            if (tmp == n) {
                p = i + 1;
                break;
            }
            if (tmp == n - 1) {
                tmp = query(1, i + 1, i, n - 1);
                if (tmp < 0)
                    return 0;
                if (tmp == n) {
                    p = i;
                    break;
                }
            }
            i += 2;
        }
        if (p < 0)
            p = n - 1;
        ans[p] = n;
        for (int i = 0; i < n; i++) {
            if (i == p)
                continue;
            int tmp = query(2, i, p, 1);
            ans[i] = tmp;
        }
        cout << "! ";
        for (int i = 0; i < n; i++)
            cout << ans[i] << ' ';
        cout << endl;
        cout.flush();
    }

    return 0;
}
