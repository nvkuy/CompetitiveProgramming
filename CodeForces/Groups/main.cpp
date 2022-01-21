#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t, n, a[1001][6], c1, c2;
    bool id;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int j = 0; j < n; j++)
            for (int i = 0; i < 5; i++)
                cin >> a[j][i];
        id = false;
        for (int i = 0; i < 4; i++) {
            if (id)
                break;
            for (int j = i + 1; j < 5; j++) {
                if (id)
                    break;
                c1 = 0, c2 = 0;
                for (int k = 0; k < n; k++) {
                    if (a[k][i] == 0 && a[k][j] == 0)
                        break;
                    if (a[k][i] == 1)
                        c1++;
                    if (a[k][j] == 1)
                        c2++;
                    if (k == n - 1) {
                        if ((a[k][i] == 1 || a[k][j] == 1) && c1 * 2 >= n && c2 * 2 >= n)
                            id = true;
                    }
                }
                //cout << "TEST: " << i << "|" << j << " " << (id ? "YES\n" : "NO\n");
            }
        }
        cout << (id ? "YES\n" : "NO\n");
    }

    return 0;
}
