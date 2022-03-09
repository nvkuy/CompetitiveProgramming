#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

vector<vector<int>> a;
map<int, vector<pair<int, int>>> cc;
map<int, vector<pair<int, int>>>::iterator it;

long long calc(vector<pair<int, int>> c) {
    long long ans = 0LL;
    for (int i = 0; i < c.size(); i++)
        for (int j = i + 1; j < c.size(); j++)
            ans += (abs(c[i].first - c[j].first) + abs(c[i].second - c[j].second));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    long long ans = 0LL;
    cin >> n >> m;
    a = vector<vector<int>>(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            cc[a[i][j]].push_back(make_pair(i, j));
        }
    }
    for (it = cc.begin(); it != cc.end(); it++)
        ans += calc((*it).second);
    cout << ans;

    return 0;
}
