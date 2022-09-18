#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long a, b, k, ans = 0;
    cin >> a >> b >> k;
    while (a < b) {
        ans++;
        a *= k;
    }
    cout << ans;

    return 0;
}
