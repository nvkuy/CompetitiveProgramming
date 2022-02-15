#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        int co = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i == 0 || i == n - 1)
                continue;
            if (a[i] == 1)
                co++;
        }
        if ((co == n - 2) || (n == 3 && a[1] % 2 == 1)) {
            cout << "-1\n";
            continue;
        }
        long long ans = 0LL;
        for (int i = 1; i < n - 1; i++)
            ans += ((a[i] + 1) / 2);
        cout << ans << endl;
    }

    return 0;
}
