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

    pair<int, int> get(int id, int l, int r, int max_val, int cur_L, int cur_R) {
        if (l == r) {
            if (cur_L + ST_L[id] <= max_val && cur_R + ST_R[id] <= max_val)
                return {cur_L + ST_L[id], cur_R + ST_R[id]};
            return {cur_L, cur_R};
        }
        int mid = (l + r) / 2;
        if (max(cur_L + ST_L[id * 2], cur_R + ST_R[id * 2]) > max_val)
            return get(id * 2, l, mid, max_val, cur_L, cur_R);
        return get(id * 2 + 1, mid + 1, r, max_val, cur_L + ST_L[id * 2], cur_R + ST_R[id * 2]);
    }

    pair<int, int> get(int max_val) {
        return get(1, 0, ts, max_val, 0, 0);
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

    int l = 0, r = n;
    while (l < r) {
        int largest_region = (l + r) / 2;
        bool iok = false;
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
            pair<int, int> tmp = ST.get(largest_region);
            int r1 = tmp.first, r2 = j - r1, r3 = tmp.second;
            int r4 = n - r2 - r3 - r1;
            vector<int> temp = {r1, r2, r3, r4};
            sort(temp.begin(), temp.end());
            if (temp.back() <= largest_region) {
                iok = true;
                break;
            }
        }
        if (iok)
            r = largest_region;
        else
            l = largest_region + 1;
    }
    cout << r << endl;

    return 0;
}