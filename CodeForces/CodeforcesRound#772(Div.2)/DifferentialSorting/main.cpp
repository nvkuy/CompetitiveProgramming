#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t, n, ai;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (a[n - 2] > a[n - 1]) {
            cout << "-1\n";
            continue;
        }
        if (a[n - 1] < 0) {
            vector<int> cpa = a;
            sort(cpa.begin(), cpa.end());
            bool iok = true;
            for (int i = 0; i < n; i++) {
                if (a[i] != cpa[i]) {
                    iok = false;
                    break;
                }
            }
            cout << (iok ? "0\n" : "-1\n");
            continue;
        }
        vector<int> ans;
        ai = a[n - 2] - a[n - 1];
        for (int i = 0; i < n - 2; i++) {
            if (a[i] != ai)
                ans.push_back(i + 1);
        }
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ' << n - 1 << ' ' << n << endl;
    }

    return 0;
}
