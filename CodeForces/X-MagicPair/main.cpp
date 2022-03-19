#include <bits/stdc++.h>

using namespace std;

bool check(long long a, long long b, long long x) {
    if (x == a || x == b)
        return true;
    if (a < b)
        swap(a, b);
    if (a == 0 || b == 0 || a < x)
        return false;
    if ((a - x) % b == 0)
        return true;
    else
        return check(a % b, b, x);
}

int main()
{
    int t;
    long long a, b, x, c;
    cin >> t;
    while (t--) {
        cin >> a >> b >> x;
        cout << (check(a, b, x) ? "YES" : "NO") << endl;
    }

    return 0;
}
