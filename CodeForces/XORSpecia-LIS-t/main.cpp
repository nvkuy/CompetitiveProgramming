#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, a[200002];
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (n % 2) {
            bool isa = false;
            for (int i = 1; i < n; i++) {
                if (a[i] <= a[i - 1]) {
                    isa = true;
                    break;
                }
            }
            cout << (isa ? "YES\n" : "NO\n");
        } else
            cout << "YES\n";
    }

    return 0;
}
