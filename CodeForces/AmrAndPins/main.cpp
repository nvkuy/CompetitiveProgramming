#include <bits/stdc++.h>

using namespace std;

int main()
{

    double r, x1, x2, y1, y2;
    int ans;
    cin >> r >> x1 >> y1 >> x2 >> y2;
    ans = ceil(sqrt(fabs(x1 - x2) * fabs(x1 - x2) + fabs(y1 - y2) * fabs(y1 - y2)) / r);
    if (ans % 2)
        ans = (ans / 2) + 1;
    else
        ans /= 2;
    cout << ans;

    return 0;
}
