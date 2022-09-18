#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, k, s;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> a(n + 1);
        for (int l = 0; l < n; l++)
            cin >> a[l];
        s = 0;
        sort(a.begin(), a.begin() + n);
        for (int i = n - k; i < n; i++)
            s += (a[i - k] / a[i]);
        for (int i = 0; i < n - (2 * k); i++)
            s += a[i];
        cout << s << endl;
    }

    return 0;
}
