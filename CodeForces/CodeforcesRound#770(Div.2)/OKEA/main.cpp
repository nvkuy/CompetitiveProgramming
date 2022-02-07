#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        if ((((n % 2) == 1 && (k % 2) == 0) || ((n % 2) == 1 && (k % 2) == 1)) && (k > 1)) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        int l = 1, c = 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                if (i % 2) {
                    cout << c << ' ';
                    c += 2;
                } else {
                    cout << l << ' ';
                    l += 2;
                }
            }
            cout << '\n';
        }
    }

    return 0;
}
