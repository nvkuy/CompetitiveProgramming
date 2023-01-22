#include <bits/stdc++.h>
using namespace std;

int main() {

    if (fopen("hoofball.in", "r")) {
        freopen("hoofball.in", "r", stdin);
        freopen("hoofball.out", "w", stdout);
    }
    
    int n;
    set<pair<int, int>> edge;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    edge.insert({0, 1});
    edge.insert({n - 1, n - 2});
    for (int i = 1; i + 1 < n; i++) {
        if (a[i] - a[i - 1] <= a[i + 1] - a[i])
            edge.insert({i, i - 1});
        else
            edge.insert({i, i + 1});
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (edge.find({i - 1, i}) == edge.end() && edge.find({i + 1, i}) == edge.end())
            ans++;
        if (i + 1 < n && edge.find({i, i + 1}) != edge.end() && edge.find({i + 1, i}) != edge.end())
            if (edge.find({i - 1, i}) == edge.end() && edge.find({i + 2, i + 1}) == edge.end())
                ans++;
    }
    cout << ans << endl;
    
    return 0;
}