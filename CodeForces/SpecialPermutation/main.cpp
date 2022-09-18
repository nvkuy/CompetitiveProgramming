#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t, n, a, b;
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        if (a > (n / 2 + 1) || b < (n / 2))
            cout << "-1\n";
        else {
            if ((a == (n / 2 + 1) && b > a) || (b == (n / 2) && b > a)) {
                cout << "-1\n";
                continue;
            }
            cout << a << " ";
            for (int i = (n / 2 + 1); i <= n; i++) {
                if (i == a || i == b)
                    continue;
                cout << i << " ";
            }
            cout << b << " ";
            for (int i = (n / 2); i >= 1; i--) {
                if (i == a || i == b)
                    continue;
                cout << i << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
