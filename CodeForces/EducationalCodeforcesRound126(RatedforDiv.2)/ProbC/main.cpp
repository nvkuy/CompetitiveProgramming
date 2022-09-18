#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

long long n;
vector<int> h;

bool check(long long day, long long fh) {
    vector<int> a = h;
    long long t1 = (day / 2) + (day % 2), t2 = day / 2, t3 = 0, t4;
    for (int i = 0; i < n; i++) {
        t4 = (fh - a[i]) / 2;
        a[i] += (min(t2, t4) * 2);
        t2 = max(t2 - t4, 0LL);
        t3 += (fh - a[i]);
    }
    return t3 <= t1;
}

long long minDay(long long fh) {
    long long l = 0, r = 1e16, m;
    while (l < r) {
        m = (l + r) / 2;
        if (check(m, fh))
            r = m;
        else
            l = m + 1;
    }
    return l;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        h.resize(n);
        int hmax = 0;
        for (int i = 0; i < n; i++) {
            cin >> h[i];
            hmax = max(hmax, h[i]);
        }
        cout << min(minDay(hmax), minDay(hmax + 1)) << endl;
    }

    return 0;
}
