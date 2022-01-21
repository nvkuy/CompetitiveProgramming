#include <bits/stdc++.h>

using namespace std;

long long cc(long long x, long long x1, long long x2, long long ci) {
    return x * (abs(x1 - x2)) + ci;
}

int main()
{
    int t, n, m, k, a, b, c, d;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        vector<vector<pair<int, long long>>> pc(n + 1);
        vector<vector<pair<int, pair<int, int>>>> lad(n + 1);
        vector<int> coi(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> coi[i];
        while (k--) {
            cin >> a >> b >> c >> d;
            lad[a].push_back(make_pair(b, make_pair(c, d)));
        }
        pc[1].push_back(make_pair(1, 0));
        for (int i = 1; i < n; i++) {
            if (pc[i].size() < 1 || lad[i].size() < 1)
                continue;
            for (int j = 0; j < lad[i].size(); j++) {
                long long pcim = 1e18 + 12;
                pair<int, pair<int, int>> p1 = lad[i][j];
                for (int k = 0; k < pc[i].size(); k++) {
                    pair<int, long long> p2 = pc[i][k];
                    pcim = min(pcim, cc(coi[i], p1.first, p2.first, p2.second));
                }
                pair<int, int> p2 = p1.second;
                pc[p2.first].push_back(make_pair(p2.second, pcim));
            }
        }
        if (pc[n].size() < 1) {
            cout << "NO ESCAPE\n";
            continue;
        }
        long long ans = 1e18 + 12;
        for (int i = 0; i < pc[n].size(); i++) {
            pair<int, long long> p = pc[n][i];
            ans = min(ans, cc(coi[n], m, p.first, p.second));
        }
        cout << ans << endl;
    }

    return 0;
}
