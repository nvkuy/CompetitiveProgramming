#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, ai, f[101][4];
    cin >> n;
    f[0][0] = 0, f[0][1] = 0, f[0][2] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> ai;
        if (ai == 0) {
            f[i][0] = max(f[i - 1][1], max(f[i - 1][2], f[i - 1][0]));
            f[i][1] = max(f[i - 1][1], max(f[i - 1][2], f[i - 1][0]));
            f[i][2] = max(f[i - 1][1], max(f[i - 1][2], f[i - 1][0]));
        } else if (ai == 1) {
            f[i][0] = max(f[i - 1][1], f[i - 1][2]);
            f[i][1] = max(f[i - 1][0], f[i - 1][2]) + 1;
            f[i][2] = max(f[i - 1][1], max(f[i - 1][2], f[i - 1][0]));
        } else if (ai == 2) {
            f[i][0] = max(f[i - 1][1], f[i - 1][2]);
            f[i][2] = max(f[i - 1][0], f[i - 1][1]) + 1;
            f[i][1] = max(f[i - 1][1], max(f[i - 1][2], f[i - 1][0]));
        } else {
            f[i][0] = max(f[i - 1][1], f[i - 1][2]);
            f[i][1] = max(f[i - 1][0], f[i - 1][2]) + 1;
            f[i][2] = max(f[i - 1][0], f[i - 1][1]) + 1;
        }
    }
    cout << (n - max(f[n][1], max(f[n][2], f[n][0])));

    return 0;
}
