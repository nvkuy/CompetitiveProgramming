#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;
    if ((m < n) || (2 * n < m) || (n % 2) || (m % 2))
        cout << "IMPOSSIBLE";
    else
        cout << (m - n) / 2 << " " << (2 * n - m) / 2;
    return 0;
}
