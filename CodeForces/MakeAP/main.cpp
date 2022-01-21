#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, a, b, c, ca, cb, cc;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        ca = 2 * b - c;
        cb = a + (c - a) / 2;
        cc = 2 * b - a;
        //cout << "TEST: " << ca << ' ' << cb << ' ' << cc << endl;
        if ((ca % a == 0 && ca > 0) || ((cb % b == 0) && ((c - a) % 2 == 0) && (cb > 0)) || (cc % c == 0 && cc > 0))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
