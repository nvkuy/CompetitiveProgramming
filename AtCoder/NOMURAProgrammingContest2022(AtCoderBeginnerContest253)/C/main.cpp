#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q, t, x, c;
    map<int, int> cnt;
    map<int, int>::iterator it;
    cin >> q;
    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> x;
            cnt[x]++;
        } else if (t == 2) {
            cin >> x >> c;
            it = cnt.find(x);
            if (it == cnt.end())
                continue;
            int m = min(c, (*it).second);
            (*it).second -= m;
            if ((*it).second <= 0)
                cnt.erase(it);
        } else {
            pair<int, int> t1 = (*cnt.begin()), t2 = (*cnt.rbegin());
            cout << t2.first - t1.first << endl;
        }
    }

    return 0;
}
