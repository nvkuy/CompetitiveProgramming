#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n), as;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        as = a;
        sort(as.begin(), as.end());
        bool iok = false;
        for (int i = 0; i < n; i++) {
            if (as[i] != a[i]) {
                iok = true;
                break;
            }
        }
        cout << (iok ? "YES" : "NO") << '\n';
    }

    return 0;
}
