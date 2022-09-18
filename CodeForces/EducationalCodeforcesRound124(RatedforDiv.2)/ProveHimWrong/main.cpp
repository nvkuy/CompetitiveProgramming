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
        if (n > 19) {
            cout << "NO\n";
            continue;
        }
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            if (i == 0)
                a[i] = 1;
            else
                a[i] = a[i - 1] * 3;
        }
        cout << "YES\n";
        for (int i = 0; i < n; i++)
            cout << a[i] << ' ';
        cout << endl;
    }

    return 0;
}
