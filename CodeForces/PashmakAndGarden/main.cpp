#include <bits/stdc++.h>

using namespace std;

int main()
{

    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2 || y1 == y2) {
        if (y1 == y2)
            cout << x1 << " " << y1 + abs(x2 - x1) << " " << x2 << " " << y2 + abs(x2 - x1);
        else
            cout << x1 + abs(y2 - y1) << " " << y1 << " " << x2 + abs(y2 - y1) << " " << y2;
    } else {
        if (abs(x1 - x2) == abs(y1 - y2))
            cout << x2 << " " << y1 << " " << x1 << " " << y2;
        else
            cout << -1;
    }

    return 0;
}
