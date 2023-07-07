#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct SegTree {

    int SKIP_VALUE = 0;
    int ts;
    vector<int> ST;

    SegTree(int tsize) {
        ts = 1;
        while (ts < tsize)
            ts *= 2;
        ST.assign(2 * ts + 2, SKIP_VALUE);
    }

    int mergeN(int n1, int n2) {
        return n1 + n2;
    }

    void build(int id, int l, int r, vector<int> &a, int n) {
        if (l >= n) {
            ST[id] = SKIP_VALUE;
            return;
        }
        if (l == r) {
            ST[id] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(id * 2, l, mid, a, n);
        build(id * 2 + 1, mid + 1, r, a, n);
        ST[id] = mergeN(ST[id * 2], ST[id * 2 + 1]);
    }

    void build(vector<int> &a, int n) {
        build(1, 0, ts, a, n);
    }

    void update(int id, int l, int r, int i, int v) {
        if (i < l || r < i) {
            return ;
        }
        if (l == r) {
            ST[id] = v;
            return ;
        }

        int mid = (l + r) / 2;
        update(id * 2, l, mid, i, v);
        update(id * 2 + 1, mid + 1, r, i, v);
        ST[id] = mergeN(ST[id * 2], ST[id * 2 + 1]);
    }

    void update(int i, int v) {
        update(1, 0, ts, i, v);
    }

    int get(int id, int l, int r, int u, int v) {
        if (v < l || r < u) {
            return SKIP_VALUE;
        }
        if (u <= l && r <= v) {
            return ST[id];
        }
        int mid = (l + r) / 2;
        return mergeN(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
    }

    int get(int l, int r) {
        return get(1, 0, ts, l, r);
    }

};

const double eps = 1e-6;
pair<int, int> s, e;

pair<double, double> cal_angle(const pair<double, double> &point) {
    return {(point.first - s.first) / (point.second - s.second), (point.first - e.first) / (point.second - e.second)};
}

map<double, int> compressFunc(vector<double> all_num) {
    sort(all_num.begin(), all_num.end());
    int num = 1;
    map<double, int> func;
    for (auto num : all_num) {
        if (func[num] == 0)
            func[num] = num++;
    }
    return func;
}

long long calFor(vector<pair<int, int>> cor) {
    int n = cor.size();
    vector<pair<double, double>> angle;
    map<int, vector<int>> cor_x;
    for (auto c : cor) {
        cor_x[c.first].push_back(c.second);
        angle.push_back(cal_angle(c));
    }
}

bool collinear(int x1, int y1, int x2, int y2, int x3, int y3) {
  return (y1 - y2) * (x1 - x3) == (y1 - y3) * (x1 - x2);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> s.first >> s.second >> e.first >> e.second;
    cin >> n;
    vector<pair<int, int>> cor_pos, cor_neg, cor_left, cor_right;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        
    }


    return 0;
}
