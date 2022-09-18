#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, c;
    cin >> t;
    while (t--) {
        cin >> n;
        c = 1;
        while (c < n - 1)
            c *= 2;
        if (c == n - 1) {
            cout << n - 1 << " 0";
            for (int i = 1; i < n - 1; i++)
                cout << ' ' << i;
            cout << endl;
        } else {
            c /= 2;
            for (int i = n - 1; i >= c; i--)
                cout << i << ' ';
            cout << "0 ";
            for (int i = c - 1; i > 0; i--)
                cout << i << ' ';
            cout << endl;
        }
    }

    return 0;
}
