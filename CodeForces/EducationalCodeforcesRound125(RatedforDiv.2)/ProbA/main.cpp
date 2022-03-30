#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, x, y;
    cin >> t;
    while (t--) {
        cin >> x >> y;
        if (x == 0 && y == 0)
            cout << "0\n";
        else if (pow((int)sqrt(x * x + y * y), 2) == (x * x + y * y))
            cout << "1\n";
        else
            cout << "2\n";
    }

    return 0;
}
