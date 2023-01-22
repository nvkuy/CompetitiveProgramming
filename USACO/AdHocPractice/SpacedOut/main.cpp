#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<vector<int>> c(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> c[i][j];
    vector<int> fr(n, 0), fc(n, 0);
    for (int i = 0; i < n; i++) {
        int ts1 = 0, s1 = 0, ts2 = 0, s2 = 0;
        for (int j = 0; j < n; j++) {
            ts1 += c[i][j];
            ts2 += c[j][i];
            if (j % 2) {
                s1 += c[i][j];
                s2 += c[j][i];
            }
        }
        fr[i] = max(s1, ts1 - s1);
        fc[i] = max(s2, ts2 - s2);
    }
    int ans = 0, tans = 0;
    for (int i = 0; i < n; i++)
        tans += fr[i];
    ans = max(ans, tans);
    tans = 0;
    for (int i = 0; i < n; i++)
        tans += fc[i];
    ans = max(ans, tans);
    cout << ans << endl;

    return 0;
}
