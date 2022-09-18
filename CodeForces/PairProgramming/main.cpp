#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, m, k, ai;
    queue<int> q1, q2;
    vector<int> ans;
    cin >> t;
    while (t--) {
        while (!q1.empty())
            q1.pop();
        while (!q2.empty())
            q2.pop();
        ans.clear();
        cin >> k >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> ai;
            q1.push(ai);
        }
        for (int i = 0; i < m; i++) {
            cin >> ai;
            q2.push(ai);
        }
        bool iok = true;
        while ((!q1.empty()) || (!q2.empty())) {
            if (!q1.empty()) {
                if (q1.front() == 0) {
                    k++;
                    ans.push_back(0);
                    q1.pop();
                    continue;
                }
            }
            if (!q2.empty()) {
                if (q2.front() == 0) {
                    k++;
                    ans.push_back(0);
                    q2.pop();
                    continue;
                }
            }
            if (!q1.empty()) {
                if (q1.front() <= k) {
                    ans.push_back(q1.front());
                    q1.pop();
                    continue;
                }
            }
            if (!q2.empty()) {
                if (q2.front() <= k) {
                    ans.push_back(q2.front());
                    q2.pop();
                    continue;
                }
            }
            iok = false;
            break;
        }
        if (iok) {
            for (int i = 0; i < ans.size(); i++)
                cout << ans[i] << ' ';
            cout << endl;
            continue;
        }
        cout << "-1\n";
    }

    return 0;
}
