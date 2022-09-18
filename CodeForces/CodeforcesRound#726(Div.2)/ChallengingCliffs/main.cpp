#include <bits/stdc++.h>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> h(n), ans;
        for (int i = 0; i < n; i++)
            cin >> h[i];
        sort(h.begin(), h.end());
        int minDiff = 1e9 + 7, imin = -1;
        for (int i = 1; i < n; i++) {
            if ((h[i] - h[i - 1]) <= minDiff) {
                minDiff = h[i] - h[i - 1];
                imin = i;
            }
        }
        if (n == 2) {
            cout << h[0] << ' ' << h[1] << endl;
            continue;
        }
        for (int i = imin; i < n; i++)
            cout << h[i] << ' ';
        for (int i = 0; i < imin; i++)
            cout << h[i] << ' ';
        cout << endl;
    }

    return 0;
}
