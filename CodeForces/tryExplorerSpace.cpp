#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int INF = 1e9, MAXN = 505, MAXK = 22;
int n, m, k;

vector<pair<int, int>> c[MAXN * MAXN];
int dis[MAXN * MAXN][MAXK / 2];

void cal() {

    int dt = k / 2;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int l = 1; l <= dt; l++)
                dis[(i - 1) * m + j][l] = INF;
            dis[(i - 1) * m + j][0] = 0;
        }
    }

    for (int step = 1; step <= dt; step++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int u = (i - 1) * m + j;
                for (auto &t : c[u]) dis[u][step] = min(dis[u][step], dis[t.first][step - 1] + t.second);
            }
        }
    }

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j + 1 <= m; j++) {
            int d;
            cin >> d;
            c[(i - 1) * m + j].push_back({(i - 1) * m + j + 1, d});
            c[(i - 1) * m + j + 1].push_back({(i - 1) * m + j, d});
        }
    }

    for (int i = 1; i + 1 <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int d;
            cin >> d;
            c[(i - 1) * m + j].push_back({i * m + j, d});
            c[i * m + j].push_back({(i - 1) * m + j, d});
        }
    }

    if (k % 2 == 0)
        cal();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (k % 2) {
                cout << -1 << ' ';
                continue;
            }
            cout << dis[(i - 1) * m + j][k / 2] * 2 << ' ';
        }
        cout << endl;
    }

    return 0;
}
