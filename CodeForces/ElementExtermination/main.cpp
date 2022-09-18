#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t, n, a[300003];
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (a[0] < a[n - 1])
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
