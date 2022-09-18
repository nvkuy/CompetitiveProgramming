#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

string s;

bool valid_pos(int pa, int pb, int l, int r) {
    if (pa > pb)
        swap(pa, pb);
    if (pa == l && pb == r)
        return true;
    if (pa == l && pb == l + 1)
        return true;
    if (pb == r && pa == r - 1)
        return true;
    return false;
}

int cal(vector<vector<int>> &f, int pa, int pb, int l, int r) {
    int nl = l, nr = r;
    if (!valid_pos(pa, pb, l, r))
        return 4;
    if (min(pa, pb) == nl)
        nl++;
    if (max(pa, pb) == nl)
        nl++;
    if (max(pa, pb) == nr)
        nr--;
    if (min(pa, pb) == nr)
        nr--;
    if (f[nl][nr] == 0) {
        if (s[pa] == s[pb])
            return 0;
        return (s[pa] < s[pb] ? 1 : -1);
    }
    return f[nl][nr];
}

int try_bob(vector<vector<int>> &f, int l, int r, int pa) {
    int res = 1;
    int pos[4] = {l, l + 1, r - 1, r};
    for (int pb : pos) {
        if (pb == pa)
            continue;
        int tmp = cal(f, pa, pb, l, r);
        if (tmp == 4)
            continue;
        res = min(res, tmp);
    }
    return res;
}

int try_alice(vector<vector<int>> &f, int l, int r) {
    int res = -1;
    int pos[2] = {l, r};
    for (int pa : pos)
        res = max(res, try_bob(f, l, r, pa));
    return res;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        getline(cin, s);
        int n = s.length();
        vector<vector<int>> f(n, vector<int>(n));
        for (int i = 0; i + 1 < n; i++) {
            if (s[i] == s[i + 1])
                f[i][i + 1] = 0;
            else
                f[i][i + 1] = 1;
        }
        for (int len = 4; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                f[i][j] = try_alice(f, i, j);
            }
        }
        if (f[0][n - 1] == 0) {
            cout << "Draw" << endl;
            continue;
        }
        cout << (f[0][n - 1] > 0 ? "Alice" : "Bob") << endl;
    }

    return 0;
}
