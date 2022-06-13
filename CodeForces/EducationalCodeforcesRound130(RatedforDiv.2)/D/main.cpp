#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<char> ans;
vector<vector<int>> c;

char query1(int i) {
    cout << "? 1 " << i + 1 << endl;
    cout.flush();
    char rp;
    cin >> rp;
    return rp;
}

int query2(int l, int r) {
    cout << "? 2 " << l + 1 << ' ' << r + 1 << endl;
    cout.flush();
    int rp;
    cin >> rp;
    return rp;
}

void dfs(int u, char cc) {
    ans[u] = cc;
    for (int i = 0; i < c[u].size(); i++) {
        int v = c[u][i];
        if (ans[v] == '0')
            dfs(v, cc);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    c.resize(n);
    ans.assign(n, '0');
    vector<int> last;
    for (int i = 0; i < n; i++) {
        int diff = query2(0, i), pos;
        if (diff > last.size()) {
            last.push_back(i);
            continue;
        }
        int l = 0, r = last.size() - 1, m;
        while (l < r) {
            m = (l + r) / 2;
            if (last.size() - m == query2(last[m] + 1, i))
                r = m;
            else
                l = m + 1;
        }
        c[i].push_back(last[r]);
        c[last[r]].push_back(i);
        vector<int> tlast;
        for (int j = 0; j < last.size(); j++)
            if (j != r)
                tlast.push_back(last[j]);
        tlast.push_back(i);
        last = tlast;
    }
    for (int i = 0; i < n; i++) {
        if (ans[i] == '0') {
            char cc = query1(i);
            dfs(i, cc);
        }
    }
    cout << "! ";
    for (int i = 0; i < n; i++)
        cout << ans[i];
    cout << endl;

    return 0;
}
