#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int cost(pair<int, int> cur_cor, pair<int, int> p1, pair<int, int> p2, pair<int, int> p3, pair<int, int> p4) {
    int max_cost = 0;
    max_cost = max(max_cost, abs(cur_cor.first - p1.first) + abs(cur_cor.second - p1.second));
    max_cost = max(max_cost, abs(cur_cor.first - p2.first) + abs(cur_cor.second - p2.second));
    max_cost = max(max_cost, abs(cur_cor.first - p3.first) + abs(cur_cor.second - p3.second));
    max_cost = max(max_cost, abs(cur_cor.first - p4.first) + abs(cur_cor.second - p4.second));
    return max_cost;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cin.ignore();
        vector<string> c(n);
        pair<int, int> p1, p2, p3, p4;
        p1 = p2 = p3 = p4 = {-1, -1};
        for (int i = 0; i < n; i++) {
            getline(cin, c[i]);
            for (int j = 0; j < m; j++) {
                if (c[i][j] == 'W')
                    continue;
                if (i + j < p1.first + p1.second || p1.first < 0)
                    p1 = make_pair(i, j);
                if (j - i > p2.second - p2.first || p2.first < 0)
                    p2 = make_pair(i, j);
                if (i - j > p3.first - p3.second || p3.first < 0)
                    p3 = make_pair(i, j);
                if (i + j > p4.first + p4.second || p4.first < 0)
                    p4 = make_pair(i, j);
            }
        }
        pair<int, int> ans = {0, 0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (cost(ans, p1, p2, p3, p4) > cost({i, j}, p1, p2, p3, p4))
                    ans = make_pair(i, j);
            }
        }
        cout << ans.first + 1 << ' ' << ans.second + 1 << endl;
    }

    return 0;
}
