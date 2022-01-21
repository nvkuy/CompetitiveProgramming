#include <bits/stdc++.h>

using namespace std;
/*
vector<vector<int>> c(101);

bool cmp(vector<int> v1, vector<int> v2) {
    return (v1.size() < v2.size());
}
*/
int main()
{

    int n, m, a[101], b[101];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        //for (int j = 0; j < n; j++)
        //    if (abs(b[i] - a[j]) <= 1)
        //        c[i].push_back(j);
        //sort(c[i].begin(), c[i].end());
    }
    sort(b + 1, b + m + 1);
    int f[101][101];
    for (int i = 0; i <= max(m, n); i++)
        f[0][i] = f[i][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if (abs(a[i] - b[j]) <= 1)
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
        }
    }
    cout << f[n][m];
    /*
    sort(c.begin(), c.end(), cmp);
    bool dd[101];
    memset(dd, false, sizeof(dd));
    int ans = 0;
    for (int i = 0; i < c.size(); i++) {
        if (c[i].size() == 0)
            continue;
        for (int j = 0; j < c[i].size(); j++) {
            if (!dd[c[i][j]]) {
                ans++;
                dd[c[i][j]] = true;
                break;
            }
        }
    }
    cout << ans;
    */
    return 0;
}
