#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, ai;
    cin >> t;
    while (t--) {
        cin >> n;
        map<int, int> cnt;
        map<int, int>::iterator it;
        for (int i = 0; i < n; i++) {
            cin >> ai;
            cnt[ai]++;
        }
        int ans = 1, rm = 0;
        it = cnt.begin();
        if ((*it).second > 1)
            rm++;
        it++;
        for (; it != cnt.end(); it++) {
            if ((*it).second > 1)
                ans++;
            else
                rm++;
        }
        ans += (rm / 2);
        cout << ans << endl;
    }

    return 0;
}
