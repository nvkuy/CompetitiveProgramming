#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, u, a[3];
    cin >> t;
    while (t--) {
        cin >> a[0] >> a[1] >> a[2] >> u;
        sort(a, a + 3);
        //cout << a[0] << endl;
        if (a[2] < u) {
            cout << 0 << endl;
            continue;
        }
        if ((a[2] % u > a[1] % u) && (a[1] >= u))
            swap(a[2], a[1]);
        if ((a[2] % u > a[0] % u) && (a[0] >= u))
            swap(a[2], a[0]);
        cout << a[0] * a[1] * (a[2] / u) << endl;
    }

    return 0;
}
