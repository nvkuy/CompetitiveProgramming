#include <bits/stdc++.h>

using namespace std;

int main()
{

    long long x;
    cin >> x;
    if ((x < 0) && (x % 10 != 0))
        x -= 10LL;
    x /= 10LL;
    cout << x;

    return 0;
}
