#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n + 1), prexor(n + 1, 0);
        bool iok = false;
        int j = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            prexor[i] = prexor[i - 1] ^ a[i];
            if (prexor[i] == 0)
                j = i;
        }
        if (prexor[n] == 0)
            iok = true;
        for (int i = j - 1; i > 0; i--) {
            if (iok)
                break;
            if (prexor[i] == prexor[n])
                iok = true;
        }
        cout << (iok ? "YES" : "NO") << '\n';
    }

    return 0;
}
