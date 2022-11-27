#include <bits/stdc++.h>
using namespace std;

double eps = 1e-9, fl = 0, ce, two = 2;

bool cmples(double d1, double d2) {
    return d1 + eps <= d2;
}

double dist(pair<double, double> p1, pair<double, double> p2) {
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

void dfs(int u, vector<int> &dd, vector<vector<int>> &c) {
    dd[u] = 1;
    for (int v : c[u]) {
        if (dd[v] == 0)
            dfs(v, dd, c);
    }
}

bool check(vector<pair<double, double>> cor, double r, double x, double y) {
    vector<vector<int>> c(cor.size());
    vector<int> dd;
    for (int i = 0; i < cor.size(); i++) {
        for (int j = i + 1; j < cor.size(); j++) {
            if (cmples(dist(cor[i], cor[j]), r * two)) {
                c[i].push_back(j);
                c[j].push_back(i);
            }
        }
    }
    for (int i = 0; i < cor.size(); i++) {
        if (cmples(cor[i].second, r)) {
            dd.assign(cor.size(), 0);
            dfs(i, dd, c);
            for (int j = 0; j < cor.size(); j++) {
                if (dd[j] == 1 && cmples(abs(cor[j].second - y), r))
                    return false;
                if (dd[j] == 1 && cmples(cor[j].first, r))
                    return false;
            }
        }
        if (cmples(cor[i].first, r)) {
            dd.assign(cor.size(), 0);
            dfs(i, dd, c);
            for (int j = 0; j < cor.size(); j++) {
                if (dd[j] == 1 && cmples(abs(cor[j].first - x), r))
                    return false;
            }
        }
        if (cmples(abs(cor[i].first - x), r)) {
            dd.assign(cor.size(), 0);
            dfs(i, dd, c);
            for (int j = 0; j < cor.size(); j++) {
                if (dd[j] == 1 && cmples(abs(cor[j].second - y), r))
                    return false;
            }
        }
    }
    return true;
}

int main() {

    cout << setprecision(8) << fixed;
    int x, y, n, t1, t2;
    cin >> x >> y;
    cin >> n;
    ce = y;
    vector<pair<double, double>> cor(n);
    for (int i = 0; i < n; i++)
        cin >> cor[i].first >> cor[i].second;
    double l = fl, r = ce, m;
    while (cmples(l, r)) {
        m = (l + r) / two;
        if (check(cor, m, x, y))
            l = m;
        else
            r = m - eps;
    }
    cout << l << endl;

    return 0;
}