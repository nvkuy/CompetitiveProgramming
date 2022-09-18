#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct worker {
    long long t, y, z;
    worker(long long ti, long long yi, long long zi) {
        t = ti;
        y = yi;
        z = zi;
    }
};

long long getNumBL(worker w, long long time) {
    long long l = 0, r = 1e9, m;
    while (l < r) {
        if (r - l == 1) {
            if (r * w.z * w.t + r * w.y <= time)
                l = r;
            break;
        }
        m = (l + r) / 2;
        if (m * w.z * w.t + m * w.y <= time)
            l = m;
        else
            r = m - 1;
    }
    long long ans = l * w.z * w.t + l * w.y;
    ans += min((time - ans) / w.t, w.z);
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, mm, ti, yi, zi;
    cin >> mm >> n;
    vector<worker> ws;
    for (int i = 0; i < n; i++) {
        cin >> ti >> yi >> zi;
        ws.push_back(worker(ti, yi, zi));
    }
    long long l = 0, r = 1e18, m;
    while (l < r) {
        m = (l + r) / 2;
        long long cntBL = 0;
        for (int i = 0; i < n; i++)
            cntBL += getNumBL(ws[i], m);
        if (cntBL >= mm)
            r = m;
        else
            l = m + 1;
    }
    vector<long long> ans(n);
    long long maxProduct = 0;
    for (int i = 0; i < n; i++) {
        ans[i] = getNumBL(ws[i], l);
        maxProduct += ans[i];
    }
    long long rm = maxProduct - mm;
    cout << l << endl;
    for (int i = 0; i < n; i++) {
        long long tmp = min(ans[i], rm);
        ans[i] -= tmp, rm -= tmp;
        cout << ans[i] << ' ';
    }

    return 0;
}
