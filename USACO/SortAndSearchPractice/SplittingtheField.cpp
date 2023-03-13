#include <bits/stdc++.h>
using namespace std;

long long cal(int n, vector<pair<int, int>> &a) {
    sort(a.begin(), a.end());
    long long l = a[0].first, r = a.back().first;
    long long ans = 2e18;
    multiset<int> s1, s2;
    for (int i = 0; i < n; i++) s2.insert(a[i].second);
    for (int i = 0; i + 1 < n; i++) {
        s1.insert(a[i].second);
        auto it = s2.lower_bound(a[i].second);
        s2.erase(it);
        if (a[i].first == a[i + 1].first) continue;
        long long a1 = (a[i].first - l) * (*s1.rbegin() - *s1.begin());
        long long a2 = (r - a[i + 1].first) * (*s2.rbegin() - *s2.begin());
        ans = min(a1 + a2, ans);
    }
    return ans;
}

int main() {

    if (fopen("split.in", "r")) {
        freopen("split.in", "r", stdin);
        freopen("split.out", "w", stdout);
    }
    
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        if (x1 == -1 || a[i].first < x1) x1 = a[i].first;
        if (y1 == -1 || a[i].second < y1) y1 = a[i].second;
        if (x2 == -1 || a[i].first > x2) x2 = a[i].first;
        if (y2 == -1 || a[i].second > y2) y2 = a[i].second;
    }
    long long original = 1LL * (x2 - x1) * (y2 - y1);
    long long optimal = min(cal(n, a), original);
    for (int i = 0; i < n; i++)
        swap(a[i].first, a[i].second);
    optimal = min(optimal, cal(n, a));
    cout << original - optimal << endl;
    
    return 0;
}