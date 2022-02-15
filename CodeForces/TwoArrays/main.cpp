#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        bool iok = true;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i])
                continue;
            if (b[i] - a[i] != 1)
                iok = false;
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
