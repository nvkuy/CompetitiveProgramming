#include <bits/stdc++.h>
using namespace std;

int main() {

    if (fopen("triangles.in", "r")) {
        freopen("triangles.in", "r", stdin);
        freopen("triangles.out", "w", stdout);
    }
    
    long long n, mod = 1e9 + 7;
    cin >> n;
    vector<pair<int, int>> p(n);
    map<int, vector<pair<int, int>>> cntX, cntY;
    vector<long long> psX(n, 0), psY(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
        cntX[p[i].first].push_back({p[i].second, i});
        cntY[p[i].second].push_back({p[i].first, i});
    }
    for (auto v : cntX) {
        vector<pair<int, int>> tmp = v.second;
        sort(tmp.begin(), tmp.end());
        long long tt = 0, pre = tmp[0].first, num = 0;
        for (int i = 0; i < tmp.size(); i++) {
            tt += (tmp[i].first - pre) * num;
            tt %= mod;
            pre = tmp[i].first;
            num++;
            psX[tmp[i].second] += tt;
            psX[tmp[i].second] %= mod;
        }
        tt = 0, pre = tmp.back().first, num = 0;
        for (int i = tmp.size() - 1; i >= 0; i--) {
            tt += (pre - tmp[i].first) * num;
            tt %= mod;
            pre = tmp[i].first;
            num++;
            psX[tmp[i].second] += tt;
            psX[tmp[i].second] %= mod;
        }
    }
    for (auto v : cntY) {
        vector<pair<int, int>> tmp = v.second;
        sort(tmp.begin(), tmp.end());
        long long tt = 0, pre = tmp[0].first, num = 0;
        for (int i = 0; i < tmp.size(); i++) {
            tt += (tmp[i].first - pre) * num;
            tt %= mod;
            pre = tmp[i].first;
            num++;
            psY[tmp[i].second] += tt;
            psY[tmp[i].second] %= mod;
        }
        tt = 0, pre = tmp.back().first, num = 0;
        for (int i = tmp.size() - 1; i >= 0; i--) {
            tt += (pre - tmp[i].first) * num;
            tt %= mod;
            pre = tmp[i].first;
            num++;
            psY[tmp[i].second] += tt;
            psY[tmp[i].second] %= mod;
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (psX[i] * psY[i]);
        ans %= mod;
        // cout << psX[i] << '|' << psY[i] << endl;
    }
    cout << ans << endl;
    
    return 0;
}