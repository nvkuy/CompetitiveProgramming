#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, ai, le, lo;
    cin >> t;
    while (t--) {
        cin >> n;
        le = lo = -1;
        bool iok = true;
        for (int i = 0; i < n; i++) {
            cin >> ai;
            if (ai % 2) {
                if (lo > ai)
                    iok = false;
                lo = ai;
            } else {
                if (le > ai)
                    iok = false;
                le = ai;
            }
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
