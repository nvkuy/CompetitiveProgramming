#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

bool check(int wait_time, int n, vector<vector<int>> &c) {
    long long curTime = wait_time - 1;
    int stopX = -1, t1, t2;
    for (int i = 0; i < n; i++) {
        int first = 0, second = 1;
        if (i % 2)
            swap(first, second);
        if (curTime < c[first][i]) {
            stopX = first, t1 = i, t2 = i - 1;
            curTime--;
            break;
        }
        curTime++;
        if (curTime < c[second][i]) {
            stopX = second, t1 = i + 1, t2 = i;
            break;
        }
        curTime++;
    }
    if (stopX < 0)
        return true;
    for (int i = t1; i < n; i++) {
        if (curTime < c[1 - stopX][i])
            return false;
        curTime++;
    }
    for (int i = n - 1; i >= t2; i--) {
        if (curTime < c[stopX][i])
            return false;
        curTime++;
    }
    return true;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<vector<int>> c(2, vector<int>(n));
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n; j++)
                cin >> c[i][j];
        c[0][0] = -1;
        int l = 0, r = 1e9, m;
        while (l < r) {
            m = (l + r) / 2;
            if (check(m, n, c))
                r = m;
            else
                l = m + 1;
        }
        cout << r + 2 * n - 1 << endl;
    }

    return 0;
}
