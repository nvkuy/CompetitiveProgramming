#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        vector<int> ans;
        queue<int> big_num, small_num;
        for (int i = 0; i < n / 2; i++)
            small_num.push(a[i]);
        for (int i = (n / 2) + (n % 2); i < n; i++)
            big_num.push(a[i]);
        bool isBig = false;
        for (int i = 0; i < n; i++) {
            if (isBig) {
                ans.push_back(big_num.front());
                big_num.pop();
            } else {
                ans.push_back(small_num.front());
                small_num.pop();
            }
            isBig = !isBig;
        }
        bool iok = true;
        for (int i = 0; i < n; i++) {
            int pre = ans[(i - 1 + n) % n], next = ans[(i + 1) % n];
            if (ans[i] > pre && ans[i] > next)
                continue;
            if (ans[i] < pre && ans[i] < next)
                continue;
            iok = false;
            break;
        }
        if (!iok) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }

    return 0;
}
