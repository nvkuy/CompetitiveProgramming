#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, am, bm;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        am = -1; bm = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] > b[i])
                swap(a[i], b[i]);
            am = max(am, a[i]);
            bm = max(bm, b[i]);
        }
        cout << am * bm << endl;
    }

    return 0;
}
