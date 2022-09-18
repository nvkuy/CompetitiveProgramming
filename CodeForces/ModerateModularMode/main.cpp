#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    long long x, y, n;
    cin >> t;
    while (t--) {
        cin >> x >> y;
        if (x > y)
            n = x + y;
        else
            n = y - ((y % x) / 2);
        cout << n << endl;
    }

    return 0;
}
