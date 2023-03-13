#include <bits/stdc++.h>
using namespace std;

int main() {

    if (fopen("rental.in", "r")) {
        freopen("rental.in", "r", stdin);
        freopen("rental.out", "w", stdout);
    }
    
    int n, m, r;
    cin >> n >> m >> r;
    vector<int> cow(n);
    for (int i = 0; i < n; i++)
        cin >> cow[i];
    vector<pair<int, int>> store(m);
    for (int i = 0; i < m; i++) 
        cin >> store[i].second >> store[i].first;
    vector<int> rent(r);
    for (int i = 0; i < r; i++)
        cin >> rent[i];
    sort(cow.begin(), cow.end(), greater<int>());
    sort(store.begin(), store.end(), greater<pair<int, int>>());
    sort(rent.begin(), rent.end(), greater<int>());
    while (rent.size() > cow.size())
        rent.pop_back();
    sort(rent.begin(), rent.end());
    long long ans = 0, tans = 0, milk = 0;
    for (int i = 0; i < rent.size(); i++)
        tans += rent[i];
    ans = tans;
    int j = 0, k = 0;
    for (int i = 0; i < cow.size(); i++) {
        milk += cow[i];
        if (i + rent.size() >= cow.size() && j < rent.size())
            tans -= rent[j++];
        while (milk > 0 && k < store.size()) {
            long long tmp = min(milk, 1LL * store[k].second);
            milk -= tmp;
            store[k].second -= tmp;
            tans += (tmp * store[k].first);
            if (store[k].second == 0)
                k++;
        }
        ans = max(ans, tans);
    }
    cout << ans << endl;

    return 0;
}