#include <bits/stdc++.h>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, x, a, b;
    cin >> t;
    while (t--) {
        cin >> x;
        b = x % 11;
        if (x - (111 * b) >= 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
