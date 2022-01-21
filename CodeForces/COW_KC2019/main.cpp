#include <bits/stdc++.h>

using namespace std;

long long n, a, b, x[101], y[101], r[101];

bool check(long long l) {
    for (int i = 0; i < n; i++)
        if ((l + r[i]) * (l + r[i]) >= (x[i] - a) * (x[i] - a) + (y[i] - b) * (y[i] - b))
            return false;
    return true;
}

int main()
{
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> r[i];
    long long l = 0, h = 2 * 1e9 + 14, m;
    while (l < h) {
        if (h - l == 1) {
            if (check(h))
                l = h;
            break;
        }
        m = (l + h) / 2;
        if (check(m))
            l = m;
        else
            h = m - 1;
    }
    cout << l << endl;

    return 0;
}
