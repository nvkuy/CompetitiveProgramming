#include <bits/stdc++.h>

using namespace std;

int query(int l, int r, vector<pair<int, int>> &c) {
    vector<int> qr;
    set<int> s;
    for (int i = l; i <= r; i++) {
        int u = c[i].first, v = c[i].second;
        if (s.find(u) == s.end()) {
            s.insert(u);
            qr.push_back(u);
        }
        if (s.find(v) == s.end()) {
            s.insert(v);
            qr.push_back(v);
        }
    }
    cout << "? " << qr.size();
    for (int i = 0; i < qr.size(); i++)
        cout << ' ' << qr[i];
    cout << '\n';
    cout.flush();
    int x;
    cin >> x;
    return x;
}

int main()
{
    int n, u, v;
    cin >> n;
    vector<pair<int, int>> c;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        c.push_back(make_pair(u, v));
    }
    int l = 0, r = c.size() - 1, m, mp = query(l, r, c);
    int a, b, tmp;
    while (l <= r) {
        if (r == l) {
            a = c[l].first;
            b = c[r].second;
            break;
        }
        m = (l + r) / 2;
        u = query(l, m, c);
        if (u == mp) {
            r = m;
            continue;
        }
        l = m + 1;
    }
    cout << "! " << a << ' ' << b;

    return 0;
}
