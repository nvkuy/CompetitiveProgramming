#include <bits/stdc++.h>
using namespace std;

struct uq {
    int l, r, v;
};

int main() {

    int n, q;
    cin >> n >> q;
    vector<int> all;
    vector<uq> updates(n);
    for (int i = 0; i < n; i++) {
        cin >> updates[i].l >> updates[i].r >> updates[i].v;
        updates[i].r--;
        all.push_back(updates[i].l);
        all.push_back(updates[i].r);
        all.push_back(updates[i].r + 1);
    }
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].first >> queries[i].second;
        queries[i].second--;
        all.push_back(queries[i].first);
        all.push_back(queries[i].second);
        all.push_back(queries[i].first - 1);
    }
    sort(all.begin(), all.end());
    map<int, int> compressFunc, decompressFunc;
    int tmp = 1;
    for (int num : all) {
        if (compressFunc[num] == 0) {
            compressFunc[num] = tmp;
            decompressFunc[tmp] = num;
            tmp++;
        }
    }
    vector<long long> ps1(tmp + 1, 0), ps2 = ps1;
    for (uq update : updates) {
        ps1[compressFunc[update.l]] += update.v;
        ps1[compressFunc[update.r + 1]] -= update.v;
    }
    for (int i = 1; i < ps1.size(); i++)
        ps1[i] += ps1[i - 1];
    for (int i = 1; i < ps2.size(); i++) {
        ps2[i] = ps2[i - 1] + ps1[i] + ps1[i - 1] * (decompressFunc[i] - decompressFunc[i - 1] - 1);
        // cout << decompressFunc[i] << ' ' << decompressFunc[i - 1] << endl;
    }
    // for (auto p : compressFunc)
    //     cout << p.first << "->" << p.second << endl;
    // for (int i = 0; i < ps2.size(); i++)
    //     cout << ps2[i] << ' ';
    // cout << endl;
    for (auto query : queries)
        cout << ps2[compressFunc[query.second]] - ps2[compressFunc[query.first - 1]] << endl;
    
    return 0;
}