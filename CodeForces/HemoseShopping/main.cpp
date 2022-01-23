#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, x;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b.begin(), b.end());
        bool iok = true;
        for (int i = 0; i < n; i++) {
            if ((a[i] != b[i]) && (i < x) && i >= (n - x)) {
                iok = false;
                break;
            }
        }
        cout << (iok ? "YES" : "NO") << '\n';
    }

    return 0;
}
