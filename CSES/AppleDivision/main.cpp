#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, ans = 1e18, s = 0LL, tmp;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        s += p[i];
    }
    for (int i = 0; i < (1 << n); i++) {
        bitset<22> choose(i);
        tmp = 0LL;
        for (int j = 0; j < p.size(); j++)
            tmp += (p[j] * choose[j]);
        ans = min(ans, llabs(s - 2LL * tmp));
    }
    cout << ans;

    return 0;
}
