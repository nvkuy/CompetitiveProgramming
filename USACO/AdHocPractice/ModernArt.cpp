#include <bits/stdc++.h>
using namespace std;

int main() {

    if (fopen("art.in", "r")) {
        freopen("art.in", "r", stdin);
        freopen("art.out", "w", stdout);
    }
    
    int n;
    cin >> n;
    vector<vector<int>> c(n, vector<int>(n));
    vector<int> cnt(10, 0);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            c[i][j] = (s[j] - '0');
            cnt[c[i][j]]++;
        }
    }
    vector<int> can_first(10, 1);
    for (int i = 1; i <= 9; i++) {
        if (cnt[i] == 0) can_first[i] = 0;
        int x1 = n + 1, y1 = n + 1, x2 = -1, y2 = -1;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (c[j][k] == i) {
                    x1 = min(x1, j);
                    y1 = min(y1, k);
                    x2 = max(x2, j);
                    y2 = max(y2, k);
                }
            }
        }
        // cout << i << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
        for (int j = x1; j <= x2; j++)
            for (int k = y1; k <= y2; k++)
                if (c[j][k] != i) can_first[c[j][k]] = 0;
    }
    int ans = 0;
    for (int i = 1; i <= 9; i++) {
        ans += can_first[i];
        // if (can_first[i])
        //     cout << i << " can be first" << endl;
    }
    cout << ans << endl;

    return 0;
}