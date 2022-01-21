#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t, a1, a2, a3;
    cin >> t;
    while (t--) {
        cin >> a1 >> a2 >> a3;
        if ((a1 + a3 - (2 * a2)) % 3 == 0)
            cout << "0\n";
        else
            cout << "1\n";
    }

    return 0;
}
