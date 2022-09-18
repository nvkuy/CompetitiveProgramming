#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n), b(n), sa, sb;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        sa = a, sb = b;
        sort(sa.begin(), sa.end());
        sort(sb.begin(), sb.end());
        vector<pair<int, int>> ans;
        vector<int> dd(n, 0);
        bool iok = true, ic = true;
        while (ic == true && iok == true) {
            ic = false;
            for (int i = 0; i < n; i++) {
                if (dd[i] != 0)
                    continue;
                ic = true;
                int j;
                for (j = 0; j < n; j++) {
                    if (dd[j] != 0 || sb[j] != b[i] || sa[j] != a[i])
                        continue;
                    break;
                }
                if (j == n) {
                    iok = false;
                    break;
                }
                dd[j] = true;
                swap(a[i], a[j]);
                swap(b[i], b[j]);
                if (i != j)
                    ans.push_back({i, j});
            }
        }
        if (!iok) {
            cout << "-1" << endl;
            continue;
        }
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << endl;
    }

    return 0;
}
