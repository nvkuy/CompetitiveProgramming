#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        if (((n - 1) / 2) + 1 < k) {
            cout << "-1\n";
            continue;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j && j % 2 == 0 && k > 0) {
                    k--;
                    cout << 'R';
                } else
                    cout << '.';
            }
            cout << '\n';
        }
    }

    return 0;
}
