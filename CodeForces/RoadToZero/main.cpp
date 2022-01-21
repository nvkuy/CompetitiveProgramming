#include <bits/stdc++.h>

using namespace std;

int main()
{

    long long t, x, y, a, b;
    cin >> t;
    while (t--) {
        cin >> x >> y >> a >> b;
        if (x < y) {
            x ^= y;
            y ^= x;
            x ^= y;
        }
        if ((2 * y * a) < (y * b))
            cout << (a * (x + y)) << '\n';
        else
            cout << ((a * (x - y)) + (b * y)) << '\n';
    }

    return 0;
}
