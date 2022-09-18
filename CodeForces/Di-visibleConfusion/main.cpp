#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, ai;
    cin >> t;
    while (t--) {
        cin >> n;
        bool iok = true;
        for (int i = 1; i <= n; i++) {
            cin >> ai;
            if (i > 100)
                continue;
            if (!iok)
                continue;
            iok = false;
            for (int j = 2; j <= i + 1; j++) {
                if (ai % j > 0) {
                    iok = true;
                    break;
                }
            }
        }
        cout << (iok ? "YES" : "NO") << '\n';
    }

    return 0;
}
