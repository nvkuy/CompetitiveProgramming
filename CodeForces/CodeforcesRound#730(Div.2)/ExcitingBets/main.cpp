#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    long long a, b, c, d;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (a == b) {
            cout << "0 0\n";
            continue;
        }
        c = llabs(a - b);
        d = a % c;
        cout << c << ' ' << min(d, c - d) << endl;
    }

    return 0;
}
