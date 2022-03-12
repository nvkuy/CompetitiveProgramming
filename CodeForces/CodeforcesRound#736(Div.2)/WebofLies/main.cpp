#include <bits/stdc++.h>

using namespace std;

void ud1(vector<int> &dm, int u, int v, int &co) {
    if (u > v) {
        if (!dm[v])
            co--;
        dm[v]++;
    } else {
        if (!dm[u])
            co--;
        dm[u]++;
    }
}

void ud2(vector<int> &dm, int u, int v, int &co) {
    if (u > v) {
        if (dm[v] == 1)
            co++;
        dm[v]--;
    } else {
        if (dm[u] == 1)
            co++;
        dm[u]--;
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, m, q, u, v, co = 0;
    cin >> n >> m;
    vector<int> dm(n + 1, 0);
    while (m--) {
        cin >> u >> v;
        ud1(dm, u, v, co);
    }
    co = 0;
    for (int i = 0; i < n; i++)
        co += (1 - (dm[i] > 0));
    cin >> q;
    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> u >> v;
            ud1(dm, u, v, co);
        } else if (t == 2) {
            cin >> u >> v;
            ud2(dm, u, v, co);
        } else
            cout << co << endl;
    }

    return 0;
}
