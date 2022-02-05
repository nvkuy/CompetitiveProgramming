#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    long long n, m, k, d;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        if (((n * (n - 1)) / 2LL < m) || (m < n - 1))
            d = 1e10;
        else {
            if (m == 0)
                d = 1;
            else {
                if (m == (n * (n - 1)) / 2LL)
                    d = 2;
                else
                    d = 3;
            }
        }
        cout << ((d > k - 1) ? "NO" : "YES") << endl;
    }

    return 0;
}
