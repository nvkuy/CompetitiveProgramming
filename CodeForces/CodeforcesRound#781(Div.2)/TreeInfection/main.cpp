#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<int> a;

bool check(int time) {
    int rm = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > time)
            rm += (a[i] - time);
        time--;
    }
    if (time >= rm)
        return true;
    return false;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, ai;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> cnt(n + 1, 0);
        a.clear();
        for (int i = 1; i < n; i++) {
            cin >> ai;
            cnt[ai]++;
        }
        a.push_back(1);
        for (int i = 1; i <= n; i++)
            if (cnt[i] > 0)
                a.push_back(cnt[i]);
        sort(a.begin(), a.end(), greater<int>());
        int l = 0, r = n + 1, m;
        while (l < r) {
            m = (l + r) / 2;
            if (check(m))
                r = m;
            else
                l = m + 1;
        }
        cout << l << endl;
    }

    return 0;
}
