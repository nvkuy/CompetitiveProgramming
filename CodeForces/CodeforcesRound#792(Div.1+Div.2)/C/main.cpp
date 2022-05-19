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
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        vector<int> tmpRow;
        pair<int, int> ans = {-1, -1};
        bool iok = true;
        for (int i = 0; i < n; i++) {
            tmpRow = a[i];
            sort(tmpRow.begin(), tmpRow.end());
            for (int j = 0; j < m; j++) {
                if (a[i][j] != tmpRow[j]) {
                    if (ans.first < 0)
                        ans.first = j;
                    else
                        ans.second = j;
                }
            }
            if (ans.first < 0)
                continue;
            for (int j = 0; j < n; j++)
                swap(a[j][ans.first], a[j][ans.second]);
            break;
        }
        for (int i = 0; i < n; i++) {
            if (!iok)
                break;
            tmpRow = a[i];
            sort(tmpRow.begin(), tmpRow.end());
            for (int j = 0; j < m; j++) {
                if (a[i][j] != tmpRow[j]) {
                    iok = false;
                    break;
                }
            }
        }
        if (!iok) {
            cout << "-1" << endl;
            continue;
        }
        if (ans.first < 0)
            ans = {0, 0};
        cout << ans.first + 1 << ' ' << ans.second + 1 << endl;
    }

    return 0;
}
