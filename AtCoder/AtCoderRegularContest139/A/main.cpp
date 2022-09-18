#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

long long getNum(long long prev, int skipBegin) {
    bitset<66> bs1(prev), bs2(0);
    int p;
    for (p = skipBegin; (1LL << p) <= prev; p++)
        if (!bs1[p])
            break;
    bs2[p] = true;
    if ((1LL << p) <= prev) {
        for (; (1LL << p) <= prev; p++)
            if (bs1[p])
                bs2[p] = true;
    }
    bs2[skipBegin] = true;
    long long ans = 0LL;
    for (int i = 0; i <= p; i++)
        ans += ((1LL << i) * bs2[i]);
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        //cout << ans << ' ';
        ans = getNum(ans, a[i]);
    }
    cout << ans;

    return 0;
}
