#include <bits/stdc++.h>

using namespace std;

void bfs(pair<int, int> st, vector<vector<bool>> a, vector<vector<char>> &trace, bool ih, vector<vector<int>> &dd, int n, int m) {
    dd = vector<vector<int>>(n, vector<int>(m, 1e9 + 7));
    int mx[4] = {-1, 0, 0, 1};
    int my[4] = {0, 1, -1, 0};
    char rm[4] = {'U', 'R', 'L', 'D'};
    queue<pair<int, int>> q;
    q.push(st);
    dd[st.first][st.second] = 0;
    if (ih)
        trace[st.first][st.second] = 'S';
    while (!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();
        //if ((u.first == 0 || u.second == 0 || u.first == n - 1 || u.second == m - 1) && (a[u.first][u.second] == true))
        //    continue;
        for (int i = 0; i < 4; i++) {
            if (u.first + mx[i] >= n || u.first + mx[i] < 0)
                continue;
            if (u.second + my[i] >= m || u.second + my[i] < 0)
                continue;
            if (dd[u.first + mx[i]][u.second + my[i]] == 1e9 + 7 && a[u.first + mx[i]][u.second + my[i]] == true) {
                dd[u.first + mx[i]][u.second + my[i]] = dd[u.first][u.second] + 1;
                if (ih)
                    trace[u.first + mx[i]][u.second + my[i]] = rm[i];
                q.push(make_pair(u.first + mx[i], u.second + my[i]));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    char c;
    vector<pair<int, int>> st;
    st.push_back(make_pair(0, 0));
    cin >> n >> m;
    vector<vector<bool>> a(n, vector<bool>(m, false));
    vector<vector<char>> trace(n, vector<char>(m, '.'));
    vector<pair<int, int>> fi;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                if (c != '#')
                    fi.push_back(make_pair(i, j));
            if (c == '#')
                continue;
            a[i][j] = true;
            if (c == 'A')
                st[0] = make_pair(i, j);
            if (c == 'M')
                st.push_back(make_pair(i, j));
        }
    }
    vector<vector<int>> dd;
    vector<int> sp1(fi.size(), 1e9 + 7), sp2(fi.size(), 1e9 + 7);
    bfs(st[0], a, trace, true, dd, n, m);
    for (int i = 0; i < fi.size(); i++) {
        sp1[i] = dd[fi[i].first][fi[i].second];
        //cout << sp1[i] << endl;
    }

    for (int i = 1; i < st.size(); i++) {
        bfs(st[i], a, trace, false, dd, n, m);
        //cout << st[i].first << ' ' << st[i].second << endl;
        /*
        cout << "TEST: \n";
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cout << dd[j][k] << ' ';
            }
            cout << endl;
        }
        */
        for (int j = 0; j < fi.size(); j++) {
            sp2[j] = min(sp2[j], dd[fi[j].first][fi[j].second]);
            //cout << fi[j].first << ' ' << fi[j].second << endl;
            //cout << sp2[j] << ' ';
        }
        //cout << endl;
    }
    bool iok = false;
    int pos;
    for (int i = 0; i < sp1.size(); i++) {
        //cout << sp1[i] << ' ' << sp2[i] << endl;
        if (sp1[i] < sp2[i]) {
            iok = true;
            pos = i;
            break;
        }
    }
    cout << (iok ? "YES" : "NO") << '\n';
    if (iok) {
        int u = fi[pos].first, v = fi[pos].second;
        cout << sp1[pos] << endl;
        //cout << u << ' ' << v << endl;
        string ans;
        while (trace[u][v] != 'S') {
            //cout << u << ' ' << v << endl;
            ans.push_back(trace[u][v]);
            if (trace[u][v] == 'D')
                u--;
            else if (trace[u][v] == 'U')
                u++;
            else if (trace[u][v] == 'L')
                v++;
            else
                v--;
        }
        reverse(ans.begin(), ans.end());
        cout << ans;
    }

    return 0;
}
