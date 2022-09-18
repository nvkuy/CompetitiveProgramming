#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t, a, b, c, d, n, cba;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        n = abs(a - b) * 2;
        if (c > n || a > n || b > n) {
            cout << "-1\n";
            continue;
        }
        cba = a - c;
        d = b - cba;
        if (d > n)
            d -= n;
        if (d <= 0)
            d += n;
        cout << d << endl;
    }

    return 0;
}
