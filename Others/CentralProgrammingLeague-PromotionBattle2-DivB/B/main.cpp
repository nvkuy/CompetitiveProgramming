#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    map<string, int> pos;
    vector<pair<int, int>> arr;
    queue<pair<int, int>> q;
    int cpos = 1;
    q.push({1, 1});
    while (!q.empty() && cpos <= (1 << 16)) {
        pair<int, int> u = q.front();
        q.pop();
        arr.push_back({u.first, u.second}), pos.insert({to_string(u.first) + "/" + to_string(u.second), cpos});
        cpos++;
        q.push({u.first, u.first + u.second}), q.push({u.first + u.second, u.second});
    }
    int t, tt, a, b;
    cin >> t;
    while (t--) {
        cin >> tt;
        if (tt == 1) {
            cin >> a;
            cout << arr[a - 1].first << ' ' << arr[a - 1].second << endl;
        } else {
            cin >> a >> b;
            cout << pos[to_string(a) + "/" + to_string(b)] << endl;
        }
    }

    return 0;
}
