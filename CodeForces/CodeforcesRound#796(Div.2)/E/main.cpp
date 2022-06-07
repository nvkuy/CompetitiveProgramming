#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int query(string s) {
    cout << "? " << s << endl;
    cout.flush();
    int rp;
    cin >> rp;
    return rp;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    string tmp, sq;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        tmp.push_back('0');
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        sq = tmp;
        sq[i] = '1';
        int li = query(sq);
        edges.push_back({li, i});
    }
    sort(edges.begin(), edges.end());
    int ans = 0;
    for (int i = 0; i < m; i++) {
        pair<int, int> edge = edges[i];
        sq = tmp;
        sq[edge.second] = '1';
        int rp = query(sq);
        if (rp - ans == edge.first) {
            ans = rp;
            tmp = sq;
        }
    }
    cout << "! " << ans;

    return 0;
}
