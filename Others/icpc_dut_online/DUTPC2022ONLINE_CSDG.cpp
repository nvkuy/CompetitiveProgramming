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

int area(pair<int, int> p1, pair<int, int> p2) {
    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
} 

vector<pair<int, int>> gen(pair<int, int> p1, pair<int, int> p2) {
    vector<pair<int, int>> ans;
    ans.push_back(p1);
    ans.push_back(p2);
    for (int i = 2; i < 4; i++) {
        int x = ans[i - 1].first + ans[i - 1].second - ans[i - 2].second;
        int y = ans[i - 1].second - ans[i - 1].first + ans[i - 2].first;
        ans.push_back({x, y});
    }
    return ans;
}

bool m[5005][5005];

bool isValid(vector<pair<int, int>> ps) {
    for (auto p : ps) {
        if (p.first > 5000 || p.first < 0 || p.second > 5000 || p.first < 0)
            return false;
        if (m[p.first][p.second] == 0)
            return false;
    }
    return true;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n;
    cin >> n;
    vector<pair<int, int>> cor(n);
    for (int i = 0; i < n; i++) {
        cin >> cor[i].first >> cor[i].second;
        m[cor[i].first][cor[i].second] = 1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            vector<pair<int, int>> tmp;
            tmp = gen(cor[i], cor[j]);
            if (isValid(tmp))
                ans = max(ans, area(tmp[0], tmp[1]));
            tmp = gen(cor[j], cor[i]);
            if (isValid(tmp))
                ans = max(ans, area(tmp[0], tmp[1]));
        }
    }
    cout << ans;

    return 0;
}
