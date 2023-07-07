#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct car {
    int id, l, r, len;
    car() {}
    car(int idx, int lx, int lenx): id(idx), l(lx), r(lx + lenx), len(lenx) {}
    bool operator < (const car &c) const {
        if (l == c.l)
            return r < c.r;
        return l < c.l;
    }
    int dist(const car &dc1, const car &uc1, const car &dc2, const car &uc2) const {
        assert(uc1.l >= dc1.r);
        assert(uc2.l >= dc2.r);
        int space = min(uc1.l, uc2.l) - max(dc1.r, dc2.r);
        return space - len;
    }
};

vector<vector<pair<int, int>>> c;
vector<int> dd;
set<car> finish, start;
car acm_car;

void dfs(int u, int min_allow) {
    assert(u < dd.size());
    assert(u < c.size());
    dd[u] = 1;
    for (auto p : c[u]) {
        if (!dd[p.first] && p.second >= min_allow)
            dfs(p.first, min_allow);
    }
}

bool iok(int min_allow) {
    fill(dd.begin(), dd.end(), 0);
    auto it = start.lower_bound(acm_car);
    if (it->l > acm_car.l)
        it--;
    assert(it->r <= acm_car.l);
    dfs(it->id, min_allow);
    for (auto u : finish)
        if (dd[u.id]) return true;
    return false;
}

int main() {

    int n, m, r;
    cin >> n >> m >> r;
    vector<vector<car>> lane_car(n);
    
    for (int i = 1; i <= m; i++) {
        int lane, begin, len;
        cin >> lane >> len >> begin;
        if (i > 1)
            lane_car[lane].push_back(car(i, begin, len));
        else
            acm_car = car(i, begin, len);
    }

    for (int i = 0; i < n; i++) {
        lane_car[i].push_back({++m, 0, 0});
        lane_car[i].push_back({++m, r, r});
        sort(lane_car[i].begin(), lane_car[i].end());
    }

    for (auto &c : lane_car[0]) start.insert(c);
    for (auto &c : lane_car[n - 1]) finish.insert(c);

    c.resize(m + 1);
    dd.resize(m + 1);
    for (int i = 0; i + 1 < n; i++) {
        for (int j = 0; j + 1 < lane_car[i].size(); j++) {
            for (int k = 0; k + 1 < lane_car[i + 1].size(); k++) {
                int td = acm_car.dist(lane_car[i][j], lane_car[i][j + 1], lane_car[i + 1][k], lane_car[i + 1][k + 1]);
                if (td >= 0) c[lane_car[i][j].id].push_back({lane_car[i + 1][k].id, td});
                td = acm_car.dist(lane_car[i + 1][k], lane_car[i + 1][k + 1], lane_car[i][j], lane_car[i][j + 1]);
                if (td >= 0) c[lane_car[i + 1][k].id].push_back({lane_car[i][j].id, td});
            }
        }
    }

    if (!iok(0)) {
        cout << "Impossible" << endl;
        return 0;
    }

    int ll = 0, rr = r, mm;
    while (ll < rr) {
        mm = (ll + rr + 1) / 2;
        if (iok(mm))
            ll = mm;
        else
            rr = mm - 1;
    }
    double ans = (1.0 * ll) / 2.0;
    cout << setprecision(6) << fixed << ans << endl;

    return 0;

}