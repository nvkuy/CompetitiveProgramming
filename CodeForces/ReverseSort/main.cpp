#include <bits/stdc++.h>

using namespace std;

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    int t, n;
    string s;
    deque<int> dq;
    vector<int> ans;
    cin >> t;
    while (t--) {
        cin >> n;
        cin.ignore();
        dq.clear(); ans.clear();
        getline(cin, s);
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (i == (n - 1)) {
                    n--;
                    continue;
                }
                dq.push_back(i);
            }
        }
        for (int i = (n - 1); i >= 0; i--) {
            if (dq.empty())
                break;
            if (s[i] == '0') {
                ans.push_back(i);
                ans.push_back(dq.front());
                dq.pop_front();
            } else
                dq.pop_back();
        }
        if (ans.empty()) {
            cout << "0\n";
            continue;
        }
        sort(ans.begin(), ans.end());
        cout << "1\n" << ans.size() << " ";
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] + 1 << " ";
        cout << endl;
    }

    return 0;
}
