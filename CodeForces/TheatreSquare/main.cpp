#include <bits/stdc++.h>

using namespace std;

long n, m, a;
long long ans;

int main()
{

    cin >> n >> m >> a;

    ans = n / a;
    if (n % a != 0)
        ans++;
    if (m % a == 0)
        ans *= (m / a);
    else
        ans *= (m / a + 1);

    cout << ans;

    return 0;
}
