#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, l, r, a, re, x;
    cin >> t;
    while (t--) {
        cin >> l >> r >> a;
        re = r % a;
        re++;
        if (re >= a)
            re -= a;
        x = max(l, r - re);
        if (x % a <= r % a)
            x = r;
        //cout << "TEST: " << x << endl;
        cout << ((x / a) + (x % a)) << endl;
    }

    return 0;
}
