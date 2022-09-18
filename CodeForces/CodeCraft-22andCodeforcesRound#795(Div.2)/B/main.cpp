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
        vector<int> a(n), ans(n);
        map<int, vector<int>> pos;
        map<int, vector<int>>::iterator it;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            pos[a[i]].push_back(i);
        }
        bool iok = true;
        for (it = pos.begin(); it != pos.end(); it++) {
            vector<int> tmp = (*it).second;
            if (tmp.size() == 1) {
                iok = false;
                break;
            }
            int last = tmp.back();
            for (int i = 1; i < tmp.size(); i++)
                ans[tmp[i]] = tmp[i - 1];
            ans[tmp[0]] = last;
        }
        if (!iok) {
            cout << "-1" << endl;
            continue;
        }
        for (int i = 0; i < n; i++)
            cout << ans[i] + 1 << ' ';
        cout << endl;
    }

    return 0;
}
