#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, w, n, wi;
    cin >> t;
    while (t--) {
        cin >> n >> w;
        multiset<int> rec;
        multiset<int>::iterator it;
        for (int i = 0; i < n; i++) {
            cin >> wi;
            rec.insert(wi);
        }
        int ans = 1, rmw = w;
        while (rec.size() > 0) {
            it = rec.upper_bound(rmw);
            if (it == rec.begin()) {
                ans++;
                rmw = w;
                continue;
            }
            it--;
            rmw -= (*it);
            rec.erase(it);
        }
        cout << ans << endl;
    }

    return 0;
}
