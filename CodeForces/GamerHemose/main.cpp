#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, h;
    cin >> t;
    while (t--) {
        cin >> n >> h;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end(), greater<int>());
        int c, tmp;
        tmp = h / (a[0] + a[1]);
        c = tmp * 2;
        h -= (tmp * (a[0] + a[1]));
        if (h > 0) {
            c++;
            h -= a[0];
        }
        if (h > 0) {
            c++;
            h -= a[1];
        }
        cout << c << endl;
    }

    return 0;
}
