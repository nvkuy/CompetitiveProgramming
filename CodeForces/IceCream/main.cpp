#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    double x, y, n;
    //int x, y, n, c, b;
    cin >> t;
    while (t--) {
        cin >> x >> y >> n;
        /*
        if (n <= x) {
            cout << n * 3 << endl;
            continue;
        }
        */
        cout << (int)(((int)(n / (x + y)) * x * 3) + (ceil(((int)n % (int)(x + y)) / x) * 3)) << endl;
        /*
        for (c = 1; c <= n; c++) {
            if ((c * (x + y)) >= n)
                break;
        }
        b = n - (c - 1) * (x + y);
        if (b == (x + y))
            cout << c * x * 3 << endl;
        else {
            cout << (b / x) * x + (c - 1) * 3 << endl;
        }
        */
    }

    return 0;
}
