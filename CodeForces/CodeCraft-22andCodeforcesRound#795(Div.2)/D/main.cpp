#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct SegTreeMin {

    long long SKIP_VALUE = 1e18 + 12;
    int ts;
    vector<long long> ST;

    SegTreeMin(int tsize) {
        ts = 1;
        while (ts < tsize)
            ts *= 2;
        ST.assign(2 * ts + 2, SKIP_VALUE);
    }

    long long mergeN(long long n1, long long n2) {
        return min(n1, n2);
    }

    void build(int id, int l, int r, long long *a, int n) {
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

    void build(long long *a, int n) {
        build(1, 0, ts, a, n);
    }

    long long get(int id, int l, int r, int u, int v) {
        if (v < l || r < u) {
            return SKIP_VALUE;
        }
        if (u <= l && r <= v) {
            return ST[id];
        }
        int mid = (l + r) / 2;
        return mergeN(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
    }

    long long get(int l, int r) {
        return get(1, 0, ts, l, r);
    }

};

struct SegTreeMax {

    long long SKIP_VALUE = -1e18 - 12;
    int ts;
    vector<long long> ST;

    SegTreeMax(int tsize) {
        ts = 1;
        while (ts < tsize)
            ts *= 2;
        ST.assign(2 * ts + 2, SKIP_VALUE);
    }

    long long mergeN(long long n1, long long n2) {
        return max(n1, n2);
    }

    void build(int id, int l, int r, long long *a, int n) {
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

    void build(long long *a, int n) {
        build(1, 0, ts, a, n);
    }

    long long get(int id, int l, int r, int u, int v) {
        if (v < l || r < u) {
            return SKIP_VALUE;
        }
        if (u <= l && r <= v) {
            return ST[id];
        }
        int mid = (l + r) / 2;
        return mergeN(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
    }

    long long get(int l, int r) {
        return get(1, 0, ts, l, r);
    }

};

int n;
long long a[200002], ps[200002];

int getMaxL(int i, SegTreeMax &stAiMax) {
    int l = 0, r = i, m;
    while (l < r) {
        m = (l + r) / 2;
        if (stAiMax.get(m, i) > a[i])
            l = m + 1;
        else
            r = m;
    }
    return r;
}

int getMaxR(int i, SegTreeMax &stAiMax) {
    int l = i, r = n - 1, m;
    while (l < r) {
        if (r - l == 1) {
            if (stAiMax.get(i, r) <= a[i])
                l = r;
            break;
        }
        m = (l + r) / 2;
        if (stAiMax.get(i, m) > a[i])
            r = m - 1;
        else
            l = m;
    }
    return l;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        SegTreeMax stAiMax = SegTreeMax(n);
        stAiMax.build(a, n);
        ps[0] = 0;
        for (int i = 0; i < n; i++)
            ps[i + 1] = ps[i] + a[i];
        SegTreeMax stPsMax = SegTreeMax(n + 1);
        stPsMax.build(ps, n + 1);
        SegTreeMin stPsMin = SegTreeMin(n + 1);
        stPsMin.build(ps, n + 1);
        bool ans = true;
        for (int i = 0; i < n; i++) {
            if (a[i] <= 0)
                continue;
            int l = getMaxL(i, stAiMax), r = getMaxR(i, stAiMax);
            long long s1 = stPsMin.get(l, i);
            long long s2 = stPsMax.get(i + 1, r + 1);
            long long slr = s2 - s1;
            //cout << a[i] << ':' << l << '|' << r << ':' << slr << endl;
            if (a[i] < slr) {
                ans = false;
                break;
            }
        }
        cout << (ans ? "YES" : "NO") << endl;
    }

    return 0;
}
