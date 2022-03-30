#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t, n, m, i, j;
    cin >> t;
    while (t--) {
        cin >> n >> m >> i >> j;
        if ((i == n && j == m) || (i == 1 && j == 1))
            cout << 1 << ' ' << m << ' ' << n << ' ' << 1 << endl;
        else
            cout << 1 << ' ' << 1 << ' ' << n << ' ' << m << endl;
    }

    return 0;
}
