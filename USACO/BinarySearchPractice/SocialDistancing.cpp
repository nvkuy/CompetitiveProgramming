#include <bits/stdc++.h>
using namespace std;

int main() {

    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<pair<long long, long long>> grass(m);
    for (int i = 0; i < m; i++) cin >> grass[i].first >> grass[i].second;
    sort(grass.begin(), grass.end());
    long long ll = 1, rr = 1e18 + 1;
    while (ll < rr) {
        long long mm = (ll + rr + 1LL) / 2LL;
        int rm = n, i = 0, ok = 1;
        long long pre = -1e18 - 7, cur;
        while (true) {
            if (rm == 0) break;
            cur = pre + mm;
            while (i < grass.size() && cur > grass[i].second) i++;
            if (i == grass.size()) {
                ok = 0;
                break;
            }
            rm--;
            if (cur < grass[i].first)
                pre = grass[i].first;
            else
                pre = cur;
        }
        if (ok)
            ll = mm;
        else
            rr = mm - 1LL;
    }
    cout << ll << endl;

    return 0;
}