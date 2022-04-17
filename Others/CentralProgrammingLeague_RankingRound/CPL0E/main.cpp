#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q, l, r;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0;  i < n; i++)
        cin >> a[i];
    while (q--) {
        map<int, int> cnt;
        map<int, int>::iterator it;
        cin >> l >> r;
        for (int i = l - 1; i < r; i++)
            cnt[a[i]]++;
        int ans = 0;
        for (it = cnt.begin(); it != cnt.end(); it++) {
            if ((*it).second == 2)
                ans++;
        }
        cout << ans << endl;
    }

    return 0;
}
