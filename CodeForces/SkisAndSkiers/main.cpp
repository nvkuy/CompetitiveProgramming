#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, a[303], b[303];
    cin >> n;
    double d, dm = 0.0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    for (int i = 0; i < n; i++) {
        d = fabs((double)(a[i]) - (double)(b[i]));
        dm += d;
    }
    cout.precision(7);
    cout << fixed << (double)(dm / n);

    return 0;
}
