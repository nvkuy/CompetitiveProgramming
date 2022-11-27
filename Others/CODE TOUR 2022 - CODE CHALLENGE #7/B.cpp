#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define int long long
#define pi pair<int, int>
#define ALL(x) x.begin(), x.end()
#define SIZE(s) (int)s.size()
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)

vector<int> left_gt(const vector<int> &h) {
    int n = SIZE(h);
    stack<int> s;
    vector<int> l(n);
    l[0] = 0;
    s.push(0);
    FOR(i, 1, n - 1) {
        while (!s.empty() && h[s.top()] >= h[i]) {
            s.pop();
        }
        if (!s.empty())
            l[i] = s.top() + 1;
        else
            l[i] = 0;
        s.push(i);
    }
    return l;
}

vector<int> right_gt(const vector<int> &h) {
    int n = SIZE(h);
    stack<int> s;
    vector<int> r(n);
    r[n - 1] = n - 1;
    s.push(n - 1);
    ROF(i, n - 2, 0) {
        while (!s.empty() && h[s.top()] >= h[i]) {
            s.pop();
        }
        if (!s.empty())
            r[i] = s.top() - 1;
        else
            r[i] = n - 1;
        s.push(i);
    }
    return r;
};

int get_max_area(const vector<int> &h) {
    int n = SIZE(h);
    auto l = left_gt(h), r = right_gt(h);
    int ans = 0;
    FOR(i, 0, n - 1) {
        ans = max(ans, h[i] * (r[i] - l[i] + 1));
    }
    return ans;
};

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n));
    FOR(i, 0, m - 1) FOR(j, 0, n - 1) cin >> a[i][j];

    vector<int> h(n);
    vector<int> row_up(m), row_down(m);
    vector<int> col_left(n), col_right(n);

    FOR(i, 0, m - 1) {
        FOR(j, 0, n - 1) {
            if (a[i][j] == 0)
                h[j] += 1;
            else
                h[j] = 0;
        }
        row_up[i] = get_max_area(h);
        if (i > 0)
            row_up[i] = max(row_up[i], row_up[i - 1]);
    }

    h = vector<int>(n, 0);
    ROF(i, m - 1, 0) {
        FOR(j, 0, n - 1) {
            if (a[i][j] == 0)
                h[j] += 1;
            else
                h[j] = 0;
        }
        row_down[i] = get_max_area(h);
        if (i != m - 1)
            row_down[i] = max(row_down[i], row_down[i + 1]);
    }

    h = vector<int>(m, 0);
    FOR(j, 0, n - 1) {
        FOR(i, 0, m - 1) {
            if (a[i][j] == 0)
                h[i] += 1;
            else
                h[i] = 0;
        }
        col_left[j] = get_max_area(h);
        if (j > 0)
            col_left[j] = max(col_left[j - 1], col_left[j]);
    }

    h = vector<int>(m, 0);
    ROF(j, n - 1, 0) {
        FOR(i, 0, m - 1) {
            if (a[i][j] == 0)
                h[i] += 1;
            else
                h[i] = 0;
        }
        col_right[j] = get_max_area(h);
        if (j != n - 1)
            col_right[j] = max(col_right[j + 1], col_right[j]);
    }

    int ans = 0;
    FOR(i, 0, n - 2) {
        if (col_left[i] && col_right[i + 1])
            ans = max(ans, col_left[i] + col_right[i + 1]);
    }
    FOR(i, 0, m - 2) {
        if (row_up[i] && row_down[i + 1])
            ans = max(ans, row_up[i] + row_down[i + 1]);
    }
    cout << ans << '\n';
}
