#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    double a, b, tmp, x, y;
    cin >> a >> b;
    if (fabs(a) < 1e-6) {
        cout << a << ' ';
        y = 1;
        if (b < 0)
            y = -1;
        cout << y;
        return 0;
    }
    tmp = b / a;
    x = sqrt(1.0 / (1.0 + tmp * tmp));
    if (a < 0)
        x = -x;
    y = tmp * x;
    cout << fixed << setprecision(12);
    cout << x << ' ' << y;

    return 0;
}
