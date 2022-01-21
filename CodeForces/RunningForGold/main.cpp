#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<vector<int>> c(n + 1, vector<int>(6));
        vector<int> co(6, 1e8);
        int ans;
        for (int i = 1; i <= n; i++) {
            int cnt = 0;
            for (int j = 1; j <= 5; j++) {
                cin >> c[i][j];
                if (c[i][j] < co[j])
                    cnt++;
            }
            if (cnt < 3)
                continue;
            for (int j = 1; j <= 5; j++)
                co[j] = c[i][j];
            ans = i;
        }
        for (int i = 1; i <= n; i++) {
            if (i == ans)
                continue;
            else {
                int cnt = 0;
                for (int j = 1; j <= 5; j++) {
                    if (c[i][j] < co[j])
                        cnt++;
                }
                if (cnt >= 3)
                    ans = -1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
