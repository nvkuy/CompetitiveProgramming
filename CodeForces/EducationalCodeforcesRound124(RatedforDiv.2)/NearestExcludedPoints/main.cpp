#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

map<long long, pair<int, int>> nearPos;
set<long long> ps;
int mx[4] = {-1, 0, 0, 1}, my[4] = {0, -1, 1, 0};

long long hashFunc(long long x, long long y) {
    if (x < 0)
        x = 1e7 - x;
    if (y < 0)
        y = 1e7 - y;
    x += 1e8, y += 1e8;
    x *= (long long)(1e9);
    return x + y;
}

void bfs(vector<pair<int, int>> &s) {
    queue<pair<int, int>> q;
    for (int i = 0; i < s.size(); i++)
        q.push(s[i]);
    while (!q.empty()) {
        pair<int, int> u = q.front(); q.pop();
        int x = u.first, y = u.second;
        pair<int, int> ans_u = nearPos[hashFunc(x, y)];
        for (int i = 0; i < 4; i++) {
            int near_x = x + mx[i], near_y = y + my[i];
            if (ps.find(hashFunc(near_x, near_y)) == ps.end() || nearPos.find(hashFunc(near_x, near_y)) != nearPos.end())
                continue;
            nearPos.insert({hashFunc(near_x, near_y), ans_u});
            q.push({near_x, near_y});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, x, y;
    cin >> n;
    vector<pair<int, int>> xys;
    vector<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        xys.push_back(make_pair(x, y));
        ps.insert(hashFunc(x, y));
    }
    for (int i = 0; i < n; i++) {
        x = xys[i].first, y = xys[i].second;
        for (int j = 0; j < 4; j++) {
            int near_x = x + mx[j], near_y = y + my[j];
            if (ps.find(hashFunc(near_x, near_y)) == ps.end()) {
                s.push_back(make_pair(x, y));
                nearPos.insert({hashFunc(x, y), {near_x, near_y}});
            }
        }
    }
    bfs(s);
    for (int i = 0; i < n; i++) {
        x = xys[i].first, y = xys[i].second;
        pair<int, int> ans = nearPos[hashFunc(x, y)];
        cout << ans.first << ' ' << ans.second << '\n';
    }

    return 0;
}
