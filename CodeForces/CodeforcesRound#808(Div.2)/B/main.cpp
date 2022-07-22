#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, l, r;
    cin >> t;
    while (t--) {
        cin >> n >> l >> r;
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            int t1 = l / i, t2 = r / i;
            if (l % i > 0) t1++;
            int num = t2 - t1 + 1;
            if (num <= 0)
                break;
            ans.push_back(t1 * i);
        }
        if (ans.size() < n) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }

    return 0;
}
