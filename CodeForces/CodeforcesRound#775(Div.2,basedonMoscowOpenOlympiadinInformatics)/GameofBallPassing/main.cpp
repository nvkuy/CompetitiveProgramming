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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        if (a[n - 1] == 0) {
            cout << "0\n";
            continue;
        }
        if (a[n - 1] == a[n - 2]) {
            cout << "1\n";
            continue;
        }
        for (int i = n - 2; i >= 0; i--) {
            a[n - 1] -= a[i];
            if (a[n - 1] < 0)
                break;
        }
        cout << max(a[n - 1], 1) << endl;
    }

    return 0;
}
