#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

bool cmpX(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2) {
    if (p1.first == p2.first)
        return p1.second.first > p2.second.first;
    return p1.first < p2.first;
}

bool cmpY(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2) {
    if (p1.second.first == p2.second.first)
        return p1.first > p2.first;
    return p1.second.first < p2.second.first;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, x, y;
    set<int> s;
    set<int>::iterator it;

    cin >> n;
    vector<pair<int, pair<int, int>>> ranges;
    vector<bool> ans1(n, false), ans2(n, false);
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        ranges.push_back(make_pair(x, make_pair(y, i)));
    }

    sort(ranges.begin(), ranges.end(), cmpX);
    for (int i = 0; i < n; i++) {
        pair<int, int> tmp = ranges[i].second;
        it = s.lower_bound(tmp.first);
        if (it != s.end())
            ans2[tmp.second] = true;
        s.insert(tmp.first);
    }
    s.clear();
    sort(ranges.begin(), ranges.end(), cmpY);
    for (int i = 0; i < n; i++) {
        pair<int, int> tmp = ranges[i].second;
        it = s.lower_bound(ranges[i].first);
        if (it != s.end())
            ans1[tmp.second] = true;
        s.insert(ranges[i].first);
    }
    for (int i = 0; i < n; i++)
        cout << ans1[i] << ' ';
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << ans2[i] << ' ';

    return 0;
}
