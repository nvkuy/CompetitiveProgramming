#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, q, ni = 0, x, y;
    string s;
    cin >> n >> m >> q;
    cin.ignore();
    vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        getline(cin, s);
        for (int j = 0; j < s.length(); j++) {
            f[i][j] = f[i - 1][j];
            if (s[j] == '*') {
                f[i][j]++;
                ni++;
            }
        }
    }
    while (q--) {
        cin >> x >> y;
        int dt = 1;
        if (f[x][y - 1] > f[x - 1][y - 1])
            dt = -1;
        for (int i = x; i <= n; i++)
            f[i][y - 1] += dt;
        ni += dt;
        int rightPlace = f[(ni % n)][ni / n];
        for (int i = 0; i < (ni / n); i++)
            rightPlace += f[n][i];
        cout << ni - rightPlace << endl;
    }

    return 0;
}
