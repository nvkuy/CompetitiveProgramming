#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t, u, v, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        if (n == 1) {
            cout << "0\n";
            continue;
        }
        vector<set<int>> c;
        vector<int> dd(n + 1, true);
        c.resize(n + 1);
        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            c[u].insert(v);
            c[v].insert(u);
        }
        queue<pair<int, int>> q;
        for (int i = 1; i <= n; i++)
            if (c[i].size() == 1)
                q.push(make_pair(i, k));
        k++;
        while (!q.empty()) {
            pair<int, int> u = q.front();
            q.pop();
            if (u.second < 1)
                continue;
            //cout << u.first << '|' << c[u.first].size() << '|' << u.second << endl;
            int v = (*c[u.first].begin());
            if (u.second < k) {
                k--;
                if (c[v].size() == 1) {
                    dd[u.first] = false;
                    u = q.front();
                    dd[u.first] = false;
                    break;
                }
            }
            dd[u.first] = false;
            if (c[u.first].size() == 1) {
                c[u.first].erase(c[u.first].begin());
                c[v].erase(c[v].find(u.first));
                if (c[v].size() == 1)
                    q.push(make_pair(v, u.second - 1));
            }
            /*
            cout << "TEST:\n";
            for (int i = 1; i <= n; i++)
                cout << c[i].size() << ' ';
            cout << endl;
            */
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (dd[i])
                ans++;
        cout << ans << endl;
    }

    return 0;
}
