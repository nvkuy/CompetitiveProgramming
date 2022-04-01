#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, ans = 0, cp = 5;
    cin >> n;
    while (cp <= n) {
        ans += (n / cp);
        cp *= 5;
    }
    cout << ans;

    return 0;
}
