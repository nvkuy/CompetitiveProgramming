#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, ai;
    map<int, int> co;
    map<int, int>::iterator it;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> ai;
        co[ai]++;
    }

    while (m--) {
        cin >> ai;
        if (co.size() == 0) {
            cout << "-1\n";
            continue;
        }
        it = co.lower_bound(ai);
        if (it == co.end())
            it--;
        while ((*it).first > ai) {
            if (it == co.begin())
                break;
            it--;
        }
        if ((*it).first > ai)
            cout << "-1\n";
        else {
            (it->second)--;
            cout << (*it).first << '\n';
            if ((*it).second <= 0)
                co.erase(it);
        }
    }

    return 0;
}
