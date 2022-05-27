#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, t, mv = 0;
    string s;
    set<string> dd;
    vector<pair<string, int>> sub;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s >> t;
        sub.push_back({s, t});
        if (dd.find(s) == dd.end()) {
            mv = max(mv, t);
            dd.insert(s);
        }
    }
    dd.clear();
    for (int i = 0; i < n; i++) {
        if (dd.find(sub[i].first) == dd.end() && sub[i].second == mv) {
            cout << i + 1;
            return 0;
        }
        dd.insert(sub[i].first);
    }

    return 0;
}
