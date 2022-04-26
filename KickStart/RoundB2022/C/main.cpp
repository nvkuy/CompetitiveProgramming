#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long tt, n, d;
    cin >> tt;
    for (int t = 1; t <= tt; t++) {
        cin >> n >> d;
        vector<long long> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        long long ans = 0;
        int l = 1, r = n;
        while (l <= r) {
            if (a[l] == 0) {
                l++;
                continue;
            }
            if (a[r] == 0) {
                r--;
                continue;
            }
            long long minOp1 = a[l], minOp2 = a[r], op;
            minOp1 = min(minOp1, d - minOp1);
            minOp2 = min(minOp2, d - minOp2);
            op = min(minOp1, minOp2);
            ans += op;
            if (minOp1 < minOp2) {
                if (op != a[l])
                    op *= -1;
            } else {
                if (op != a[r])
                    op *= -1;
            }
            for (int i = l; i <= r; i++)
                a[i] = (a[i] + d - op) % d;
            /*
            cout << l << '|' << r << endl;
            for (int i = 1; i <= n; i++)
                cout << a[i] << ' ';
            cout << endl;
            */
        }
        cout << "CASE #" << t << ": " << ans << endl;
    }

    return 0;
}
