#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, ai, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        map<int, int> cnt;
        map<int, int>::iterator it;
        for (int i = 0; i < n; i++) {
            cin >> ai;
            cnt[ai]++;
        }
        int l = 0, r = -1, tl, tr, pre = -1;
        for (it = cnt.begin(); it != cnt.end(); it++) {
            if ((*it).second < k) {
                tl = 0, tr = -1;
                continue;
            }
            if ((*it).first - pre > 1)
                tl = 0, tr = -1;
            pre = (*it).first;
            if (tl < 1)
                tl = (*it).first;
            tr = (*it).first;
            if (tr - tl > r - l)
                r = tr, l = tl;
        }
        if (r - l < 0) {
            cout << "-1" << endl;
            continue;
        }
        cout << l << ' ' << r << endl;
    }

    return 0;
}
