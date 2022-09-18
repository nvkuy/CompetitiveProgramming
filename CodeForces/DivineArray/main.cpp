#include <bits/stdc++.h>

using namespace std;

int t, n, c[2002], f[2002][2002], q, x, k;

int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        memset(c, 0, sizeof(c));
        for (int i = 0; i < n; i++) {
            cin >> f[0][i];
            c[f[0][i]]++;
        }
        for (int i = 1; i <= 2000; i++) {
            //for (int j = 0; j <= 6; j++)
            //    cout << c[j] << " ";
            //cout << endl;
            for (int j = 0; j < n; j++)
                f[i][j] = c[f[i - 1][j]];
            memset(c, 0, sizeof(c));
            for (int j = 0; j < n; j++)
                c[f[i][j]]++;
        }
        /*
        for (int i = 0; i <= 6; i++) {
            for (int j = 0; j < n; j++)
                cout << f[i][j] << " ";
            cout << endl;
        }
        */
        cin >> q;
        while (q--) {
            cin >> x >> k;
            cout << f[min(k, 2000)][x - 1] << endl;
        }
    }

    return 0;
}
