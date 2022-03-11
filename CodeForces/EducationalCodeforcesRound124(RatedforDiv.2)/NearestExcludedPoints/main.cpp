#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

set<string> ps;
int mx[4] = {-1, 0, 0, 1}, my[4] = {0, -1, 1, 0};

string pts(int x, int y) {
    string tmp = to_string(x) + '|' + to_string(y);
    return tmp;
}

pair<int, int> bfs(int x, int y) {
    set<string> dd;
    dd.insert(pts(x, y));
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    while (!q.empty()) {
        pair<int, int> u = q.front();
        //cout << "VIS: " << u.first << ' ' << u.second << endl;
        q.pop();
        if (ps.find(pts(u.first, u.second)) == ps.end() && abs(u.first) <= 1e6 && abs(u.second) <= 1e6)
            return u;
        for (int i = 0; i < 4; i++) {
            int xt = u.first + mx[i];
            int yt = u.second + my[i];
            string tmp = pts(xt, yt);
            if (dd.find(tmp) == dd.end()) {
                dd.insert(tmp);
                q.push(make_pair(xt, yt));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, x, y;
    cin >> n;
    vector<pair<int, int>> xys;
    ps.clear();
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        xys.push_back(make_pair(x, y));
        ps.insert(pts(x, y));
    }
    for (int i = 0; i < n; i++) {
        pair<int, int> ans = bfs(xys[i].first, xys[i].second);
        cout << ans.first << ' ' << ans.second << endl;
    }

    return 0;
}
