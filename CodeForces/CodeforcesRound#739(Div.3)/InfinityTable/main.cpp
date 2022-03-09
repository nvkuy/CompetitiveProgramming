#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t, n, k, r, row, col;
    cin >> t;
    while (t--) {
        cin >> k;
        if (k == 1) {
            cout << "1 1\n";
            continue;
        }
        n = 1;
        while (pow(n + 1, 2) < k)
            n++;
        r = k - (n * n);
        //cout << "TEST: " << r << '|' << n << endl;
        col = n + 1, row = 0;
        for (int i = 0; i <= n; i++) {
            if (r <= 0)
                break;
            r--;
            row++;
        }
        for (int i = 1; i <= n; i++) {
            if (r <= 0)
                break;
            r--;
            col--;
        }
        cout << row << ' ' << col << endl;
    }

    return 0;
}
