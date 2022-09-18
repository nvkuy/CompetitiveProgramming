#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

void go(char c, int &x, int &y) {
    if (c == 'E')
        x = min(x + 1, 20);
    if (c == 'W')
        x = max(x - 1, 0);
    if (c == 'S')
        y = max(y - 1, 0);
    if (c == 'N')
        y = min(y + 1, 20);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, x, y, l, rn;
    vector<vector<int>> dd(1001, vector<int>(22, 0));
    cin >> n;
    while (n != 0) {
        fill(dd.begin(), dd.end(), vector<int>(22, 0));
        rn = 0;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            if (dd[x][y] == 0) {
                dd[x][y] = 1;
                rn++;
            }
        }
        cin >> m;
        char c;
        x = y = 10, n = rn;
        n -= dd[x][y];
        dd[x][y] = 0;
        while (m--) {
            cin >> c >> l;
            //if (x > 20 || x < 0 || y > 20 || y < 0)
            //    continue;
            for (int i = 0; i < l; i++) {
                go(c, x, y);
                //if (x > 20 || x < 0 || y > 20 || y < 0)
                //    break;
                n -= dd[x][y];
                dd[x][y] = 0;
            }
        }
        cout << (n == 0 ? "Yes" : "No") << endl;
        cin >> n;
    }

    return 0;
}
