#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, a[51];
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        cout << a[n - 1] - a[0] << endl;
    }

    return 0;
}
