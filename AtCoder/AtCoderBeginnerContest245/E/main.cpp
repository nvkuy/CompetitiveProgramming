#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i].first;
    for (int i = 0; i < n; i++)
        cin >> a[i].second;
    for (int i = 0; i < m; i++)
        cin >> b[i].first;
    for (int i = 0; i < m; i++)
        cin >> b[i].second;
    sort(a.begin(), a.end(), greater<pair<int, int>>());
    sort(b.begin(), b.end(), greater<pair<int, int>>());
    multiset<int> rm;
    multiset<int>::iterator it;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < m && a[i].first <= b[j].first) {
            rm.insert(b[j].second);
            j++;
        }
        it = rm.lower_bound(a[i].second);
        if (it == rm.end()) {
            cout << "No";
            return 0;
        }
        rm.erase(it);
    }
    cout << "Yes";

    return 0;
}
