#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        if ((n - k) <= k) {
            cout << "-1" << endl;
            continue;
        }
        deque<int> ans, tmp;
        for (int i = 1; i <= n; i++)
            tmp.push_back(i);
        for (int i = 0; i < k; i++) {
            ans.push_back(tmp.front()); tmp.pop_front();
            ans.push_back(tmp.back()); tmp.pop_back();
        }
        while (!tmp.empty()) {
            ans.push_back(tmp.front());
            tmp.pop_front();
        }
        for (int i = 0; i < n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }

    return 0;
}
