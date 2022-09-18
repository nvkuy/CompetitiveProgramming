#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

long long n;
bool check(long long a, long long b) {
    long long x = a * a * a;
    if (x >= n)
        return true;
    x += (b * b * b);
    if (x >= n)
        return true;
    x += (a * b * b);
    if (x >= n)
        return true;
    x += (a * a * b);
    if (x >= n)
        return true;
    return false;
}

long long findX(long long a) {
    long long l = 0, r = 1e6, m;
    while (l < r) {
        m = (l + r) / 2;
        if (check(a, m))
            r = m;
        else
            l = m + 1;
    }
    return (a * a * a) + (a * a * l) + (a * l * l) + (l * l * l);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long ans = 1e18;
    cin >> n;
    for (long long a = 0; a <= 1e6; a++)
        ans = min(ans, findX(a));
    cout << ans;

    return 0;
}
