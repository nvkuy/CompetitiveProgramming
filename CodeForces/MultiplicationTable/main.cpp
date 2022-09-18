#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, x, ans;
    cin >> n >> x;
    ans = 0;
    for (int i = 1; i <= n; i++) {
        if (x % i)
            continue;
        if ((x / i) <= n)
            ans++;
    }
    cout << ans;

    return 0;
}
