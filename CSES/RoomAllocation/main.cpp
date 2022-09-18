#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k = 1, a, b, maxb = 0;
    multimap<int, int> rooms;
    multimap<int, int>::iterator it;

    cin >> n;
    vector<int> ans(n);
    vector<pair<int, pair<int, int>>> cust;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cust.push_back(make_pair(a, make_pair(b, i)));
        maxb = max(maxb, b);
    }

    rooms.insert(make_pair(maxb + 1, k));
    sort(cust.begin(), cust.end());
    for (int i = n - 1; i >= 0; i--) {
        pair<int, int> tmp = cust[i].second;
        it = rooms.upper_bound(tmp.first);
        if (it == rooms.end()) {
            k++;
            rooms.insert(make_pair(cust[i].first, k));
            ans[tmp.second] = k;
        } else {
            int room = (it->second);
            rooms.erase(it);
            rooms.insert(make_pair(cust[i].first, room));
            ans[tmp.second] = room;
        }
    }

    cout << k << endl;
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';

    return 0;
}
