#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, s = 0LL, am = 0, ai;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ai;
        s += ai;
        am = max(am, ai);
    }
    if (s - am <= am)
        cout << 2 * am;
    else
        cout << s;

    return 0;
}
