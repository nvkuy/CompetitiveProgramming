#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first == p2.first)
        return p1.second > p2.second;
    return p1.first < p2.first;
}

int main() {

    if (fopen("mountains.in", "r")) {
        freopen("mountains.in", "r", stdin);
        freopen("mountains.out", "w", stdout);
    }
    
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        a[i] = {a[i].first - a[i].second, a[i].first + a[i].second};
    }
    sort(a.begin(), a.end(), cmp);
    int maxR = 0;
    vector<int> canSee(n, 1);
    for (int i = 0; i < n; i++) {
        if (a[i].second <= maxR)
            canSee[i] = 0;
        maxR = max(maxR, a[i].second);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += canSee[i];
    cout << ans << endl;
    
    return 0;
}