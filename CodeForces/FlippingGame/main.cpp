#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, am, a[101], b[101], c, l, r, j;
    cin >> n;
    a[0] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = (a[i] ? -1 : 1);
        a[i] += a[i - 1];
    }
    am = 0, c = 0, j = 0, l = 0, r = 0;
    for (int i = 1; i <= n; i++) {
        c += b[i];
        if (c < 0) {
            j = i;
            c = 0;
            continue;
        }
        if (c > am) {
            am = c;
            l = j;
            r = i;
        }
    }
    if (l - r == 0)
        cout << (a[n] - 1);
    else
        cout << a[n] + r - l - (2 * a[r]) + (2 * a[l]);

    return 0;
}
