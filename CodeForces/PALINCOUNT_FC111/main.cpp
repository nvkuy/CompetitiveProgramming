#include <bits/stdc++.h>

using namespace std;

long long calA(long long n, long long k) {
    if (n - k >= 0) {
        if (k == 2)
            return n * (n - 1);
        return n * (n - 1) * (n - 2);
    }
    return 0;
}

int main()
{
    int t;
    long long x, y, ans;
    cin >> t;
    while (t > 0) {
        t--;
        ans = 0;
        cin >> x >> y;
        ans += calA(x, 3); ans += calA(y, 3);
        ans += (calA(x, 2) * y); ans += (calA(y, 2) * x);
        cout << ans << "\n";
    }

    return 0;
}
