#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    double a, b, c, x, ans;
    cin >> a >> b >> c >> x;
    if (x <= a)
        ans = 1.0;
    else if (x > b)
        ans = 0.0;
    else
        ans = c / (b - a);
    cout << setprecision(10) << fixed;
    cout << ans;

    return 0;
}
