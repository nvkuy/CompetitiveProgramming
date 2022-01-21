#include <bits/stdc++.h>

using namespace std;

int f[2][100001];

int main()
{
    int t, m, aij, m1, m2;
    cin >> t;
    while (t--) {
        cin >> m;
        f[0][0] = 0, f[1][0] = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> aij;
                f[i][j] = f[i][j - 1] + aij;
            }
        }
        m1 = 1e9 + 7;
        for (int i = 1; i <= m; i++) {
            m2 = max(f[0][m] - f[0][i], f[1][i - 1]);
            m1 = min(m1, m2);
        }
        cout << m1 << endl;
    }

    return 0;
}
