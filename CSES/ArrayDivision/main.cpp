#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n, k;
vector<int> a;

bool check(long long max_sum) {
    vector<long long> parts;
    long long cs = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > max_sum)
            return false;
        cs += a[i];
        if (cs <= max_sum)
            continue;
        cs -= a[i];
        parts.push_back(cs);
        cs = a[i];
    }
    parts.push_back(cs);
    if (parts.size() > k)
        return false;
    return true;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long l = 0, r = 1e15, m;
    while (l < r) {
        m = (l + r) / 2LL;
        if (check(m))
            r = m;
        else
            l = m + 1;
    }
    cout << r;

    return 0;
}
