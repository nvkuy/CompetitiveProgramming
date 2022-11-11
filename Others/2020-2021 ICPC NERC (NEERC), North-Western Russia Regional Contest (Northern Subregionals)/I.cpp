#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int s, x = -1, y = -1;
    cin >> s;
    for (int i = 0; i * i <= s; i++) {
        int j = s - i * i;
        int tmp = sqrt(j);
        if ((tmp * tmp) == j) {
            x = i, y = tmp;
            break;
        }
    }
    if (x < 0) {
        cout << "Impossible" << endl;
        return 0;
    }
    int dx = x, dy = y, curx = 0, cury = 0;
    for (int i = 0; i < 4; i++) {
        cout << curx << ' ' << cury << endl;
        curx -= dx, cury += dy;
        swap(dx, dy);
        dx *= -1;
    }

    return 0;
}
