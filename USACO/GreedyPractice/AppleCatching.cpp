#include <bits/stdc++.h>
using namespace std;

struct event {

    int q, t, x, n;

    bool operator < (const event &e) const {
        return (x + t) < (e.x + e.t);
    }

};

bool cmp(const event &e1, const event &e2) {
    if ((e1.x - e1.t) == (e2.x - e2.t))
        return e1.q < e2.q;
    return (e1.x - e1.t) > (e2.x - e2.t);
}

int main() {

    int n;
    cin >> n;
    vector<event> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].q >> a[i].t >> a[i].x >> a[i].n;
    sort(a.begin(), a.end(), cmp);
    multiset<event> rm;
    int ans = 0;
    for (auto e : a) {
        if (e.q == 1) {
            rm.insert(e);
            continue;
        }
        while (true) {
            auto it = rm.upper_bound(e);
            if (rm.size() == 0 || it == rm.begin()) break;
            it--;
            event tmp1 = *it;
            rm.erase(it);
            int tmp2 = min(e.n, tmp1.n);
            e.n -= tmp2; 
            tmp1.n -= tmp2;
            ans += tmp2;
            if (tmp1.n > 0) rm.insert(tmp1);
            if (e.n == 0) break;
        }
    }
    cout << ans << endl;

    return 0;
}