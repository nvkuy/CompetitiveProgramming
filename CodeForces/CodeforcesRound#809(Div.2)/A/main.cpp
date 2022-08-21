#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        string ans;
        for (int i = 0; i < m; i++)
            ans.push_back('B');
        for (int i = 0; i < n; i++) {
            int pos = min(a[i], m - a[i] + 1);
            if (ans[pos - 1] == 'B') {
                ans[pos - 1] = 'A';
                continue;
            }
            pos = m - pos + 1;
            ans[pos - 1] = 'A';
        }
        cout << ans << endl;
    }

    return 0;
}
