#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    long long n, k, r, c, i;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        i = 0;
        c = 1, r = -1;
        while (c < n) {
            c *= 2;
            i++;
            if (c > n)
                break;
            if (c > k) {
                r = (n - c) / k;
                if ((n - c) % k > 0)
                    r++;
                break;
            }
        }
        if (r >= 0)
            i += r;
        cout << i << endl;
    }

    return 0;
}
