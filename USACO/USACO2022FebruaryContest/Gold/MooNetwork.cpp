#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int n, m;
vector<vector<pair<int, long long>>> c;
vector<long long> dis;

long long prim(int s) {
    long long ret = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;

    fill(dis.begin(), dis.end(), INF);

    dis[s] = 0;
    q.push({0, s});

    while (!q.empty()) {
        auto top = q.top(); q.pop();
        long long curDis = top.first; int u = top.second;

        if (curDis != dis[u]) continue;

        ret += dis[u]; dis[u] = -INF;

        for (auto &e : c[u]) {
            int v = e.first; long long cc = e.second;
            if (dis[v] > cc) {
                dis[v] = cc;
                q.push({dis[v], v});
            }
        }
    }
    return ret;
}

long long dist(pair<long long, long long> p1, pair<long long, long long> p2) {
    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}

int main()
{
    
    int n;
    cin >> n;
    vector<pair<int, int>> cors(n);
    for (int i = 0; i < n; i++)
        cin >> cors[i].first >> cors[i].second;
    c.resize(n);
    dis.resize(n);
    sort(cors.begin(), cors.end());
    map<int, vector<int>> tmp;
    for (int i = 0; i < n; i++)
        tmp[cors[i].first].push_back(i);
    vector<vector<int>> corx;
    for (auto t : tmp)
        corx.push_back(t.second);
    for (int i = 0; i < corx.size(); i++) {
        for (int u : corx[i]) {
            for (int j = i + 1; j < n; j++) {
                for (int v : corx[j]) {
                    c[u].push_back({v, dist(cors[u], cors[v])});
                    c[v].push_back({u, dist(cors[u], cors[v])});
                }
                if (cors[corx[j][0]].first - cors[corx[i][0]].first > 10)
                    break;
            }
            for (int v : corx[i]) {
                if (u != v)
                    c[u].push_back({v, dist(cors[u], cors[v])});
            }
        }
    }
    cout << prim(0) << endl;;

    return 0;
}
