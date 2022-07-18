#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n;
vector<vector<int>> c;
vector<int> dd;
set<int> infected;

vector<int> readArr() {
    string s, tmp;
    getline(cin, s);
    while (s.back() == ' ')
        s.pop_back();
    int j = 0;
    vector<int> rs;
    for (int i = 0; i <= s.length(); i++) {
        if (i >= s.length() || s[i] == ' ') {
            tmp = s.substr(j, i - j);
            j = i + 1;
            rs.push_back(stoi(tmp));
        }
    }
    return rs;
}

int bfs(int x) {
    int ans = n + 1;
    queue<int> q;
    dd[x] = 0;
    q.push(x);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (infected.find(u) != infected.end()) {
            ans = min(ans, dd[u]);
            //cout << u << '|' << dd[u] << endl;
        }
        for (int v : c[u]) {
            if (dd[v] == -1) {
                q.push(v);
                dd[v] = dd[u] + 1;
            }
        }
    }
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int x;
    string s;
    cin >> n >> x;
    cin.ignore();
    c.resize(n + 1);
    dd.assign(n + 1, -1);
    vector<int> tmp;
    tmp = readArr();
    for (int i = 0; i < tmp.size(); i++)
        infected.insert(tmp[i]);
    for (int i = 1; i <= n; i++) {
        tmp = readArr();
        for (int j = 0; j < tmp.size(); j++) {
            c[i].push_back(tmp[j]);
            c[tmp[j]].push_back(i);
        }
    }
    cout << "F" << bfs(x);

    return 0;
}
