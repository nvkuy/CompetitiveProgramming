#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, k;
    cin >> n >> k;
    vector<vector<int>> c(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> c[i][j];
    int l = 0, r = 1e9, m;
    while (l < r) {
        m = (l + r) / 2;
        vector<vector<int>> higher(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (c[i][j] > m)
                    higher[i + 1][j + 1]++;
                higher[i + 1][j + 1] += (higher[i + 1][j] + higher[i][j + 1] - higher[i][j]);
            }
        }
        bool iok = false;
        for (int i = k; i <= n; i++) {
            if (iok) break;
            for (int j = k; j <= n; j++) {
                if (iok) break;
                int higher_cnt = higher[i][j] - higher[i][j - k] - higher[i - k][j] + higher[i - k][j - k];
                if (higher_cnt < ((k * k / 2) + 1))
                    iok = true;
            }
        }
        if (iok)
            r = m;
        else
            l = m + 1;
    }
    cout << r << endl;

    return 0;
}