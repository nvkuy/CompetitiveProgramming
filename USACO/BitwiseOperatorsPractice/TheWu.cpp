#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define endl '\n'

inline int binToNum(const string &s) {
    int res = 0;
    for (int i = 0; i < s.length(); i++)
        res |= ((s[i] - '0') << i);
    return res;
}

vector<vector<pair<long long, int>>> ans;
vector<long long> mask_sum;
vector<int> cnt, w;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, q;
    cin >> n >> m >> q;
    
    ans.resize(1 << n);
    mask_sum.resize(1 << n);
    cnt.resize(1 << n);
    w.resize(n);

    for (int i = 0; i < n; i++)
        cin >> w[i];
    while (m--) {
        string s;
        cin >> s;
        int tmp = binToNum(s);
        cnt[tmp]++;
    }

    for (int i = 0; i < (1 << n); i++) {
        long long cost = 0;
        for (int j = 0; j < n; j++)
            cost += (((i >> j) & 1) * w[j]);
        mask_sum[i] = cost;
    }

    for (int i = 0; i < (1 << n); i++) {
        map<long long, int> tmp;
        for (int j = 0; j < (1 << n); j++)
            tmp[mask_sum[((~(i ^ j))) & ((1 << n) - 1)]] += cnt[j];
        for (auto &p : tmp) {
            if (p.second == 0) continue;
            if (ans[i].size() == 0) {
                ans[i].push_back(p);
                continue;
            }
            if (ans[i].back().first == p.first)
                ans[i].back().second += p.second;
            else {
                int pre = ans[i].back().second;
                ans[i].push_back(p);
                ans[i].back().second += pre;
            }
        }
    }

    while (q--) {
        string s;
        int k, num;
        cin >> s >> k;
        num = binToNum(s);
        if (ans[num].size() == 0 || ans[num].begin()->first > k) {
            cout << 0 << endl;
            continue;
        }
        int ll = 0, rr = ans[num].size() - 1, mm;
        while (ll < rr) {
            mm = (ll + rr + 1) / 2;
            if (ans[num][mm].first <= k)
                ll = mm;
            else
                rr = mm - 1;
        }
        cout << ans[num][ll].second << endl;
    }

    return 0;
}