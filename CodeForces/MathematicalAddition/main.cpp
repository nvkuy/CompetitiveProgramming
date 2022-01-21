#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{

    long long t, u, v, a, b, c;
    cin >> t;
    while (t > 0) {
        t--;
        cin >> u >> v;
        a = v * v;
        b = u * u;
        c = gcd(a, b);
        cout << - (b / c) << " " << ((long long)(a / c)) << '\n';

    }

    return 0;
}
