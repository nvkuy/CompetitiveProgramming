#include <bits/stdc++.h>
using namespace std;

const int max_size = 8 * 1e5 + 7, SKIP_VALUE = 0;
int ST_L[max_size], ST_R[max_size];

struct SegTree {

    int ts;

    SegTree(int tsize) {
        ts = 1;
        while (ts < tsize)
            ts *= 2;
        memset(ST_L, 0, (2 * ts + 2) * sizeof(ST_L[0]));
        memset(ST_R, 0, (2 * ts + 2) * sizeof(ST_R[0]));
    }

    int mergeN(int n1, int n2) {
        return n1 + n2;
    }

    void update(int id, int l, int r, int i, bool justRight) {
        if (i < l || r < i) {
            return ;
        }
        if (l == r) {
            if (!justRight) {
                ST_L[id]++;
                ST_R[id]--;
            } else
                ST_R[id]++;
            return ;
        }

        int mid = (l + r) / 2;
        update(id * 2, l, mid, i, justRight);
        update(id * 2 + 1, mid + 1, r, i, justRight);
        if (!justRight)
            ST_L[id] = mergeN(ST_L[id * 2], ST_L[id * 2 + 1]);
        ST_R[id] = mergeN(ST_R[id * 2], ST_R[id * 2 + 1]);
    }

    void update(int i, bool justRight) {
        update(1, 0, ts, i, justRight);
    }

    int get(int id, int l, int r, int r1, int r2, int r3, int r4) {
        // r1 r2
        // r3 r4
        if (l == r)
            return min(max(max(r1 + ST_L[id], r2 + ST_R[id]), max(r3, r4)), max(max(r3 + ST_L[id], r4 + ST_R[id]), max(r1, r2)));
        int m = (l + r) / 2;
        int sol1 = max(max(r1 + ST_L[id * 2], r2 + ST_R[id * 2]), max(r3, r4));
        int sol2 = max(max(r1, r2), max(r3 + ST_L[id * 2 + 1], r4 + ST_R[id * 2 + 1]));
        if (sol1 < sol2)
            return get(id * 2 + 1, m + 1, r, r1 + ST_L[id * 2], r2 + ST_R[id * 2], r3, r4);
        return get(id * 2, l, m, r1, r2, r3 + ST_L[id * 2 + 1], r4 + ST_R[id * 2 + 1]);
    }

    int get() {
        return get(1, 0, ts, 0, 0, 0, 0);
    }

};

int main() {

    if (fopen("balancing.in", "r")) {
        freopen("balancing.in", "r", stdin);
        freopen("balancing.out", "w", stdout);
    }

    int n;
    cin >> n;
    pair<int, int> *cow = new pair<int, int>[n];
    for (int i = 0; i < n; i++) cin >> cow[i].first >> cow[i].second;

    vector<int> all_cor;
    for (int i = 0; i < n; i++) {
        all_cor.push_back(cow[i].first);
        all_cor.push_back(cow[i].second);
    }

    int max_num = 1;
    map<int, int> hashFunc;
    sort(all_cor.begin(), all_cor.end());
    for (int ai : all_cor) {
        if (hashFunc.find(ai) == hashFunc.end())
            hashFunc[ai] = max_num++;
    }
    for (int i = 0; i < n; i++)
        cow[i] = {hashFunc[cow[i].first], hashFunc[cow[i].second]};

    sort(cow, cow + n);

    int ans = 1e9 + 7;
    SegTree ST = SegTree(max_num);
    for (int i = 0; i < n; i++)
        ST.update(cow[i].second, true);
    int j = 0;
    for (int i = 0; i <= max_num; i++) {
        bool new_cow = false;
        while (j < n && cow[j].first <= i) {
            ST.update(cow[j].second, false);
            j++;
            new_cow = true;
        }
        if (!new_cow && i > 0) continue;
        ans = min(ans, ST.get());
    }

    cout << ans << endl;

    return 0;
}