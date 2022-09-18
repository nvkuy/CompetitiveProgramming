#include <bits/stdc++.h>

using namespace std;

bool check(int s) {
    for (int i = 2; i * i <= s; i++)
        if (s % i == 0)
            return true;
    return false;
}

int main()
{

    int t, n, ai, s;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> ans, od;
        s = 0;
        for (int i = 1; i <= n; i++) {
            cin >> ai;
            s += ai;
            if (ai % 2)
                od.push_back(i);
            else
                ans.push_back(i);
        }
        if (!check(s))
            od.pop_back();
        for (int i = 0; i < od.size(); i++)
            ans.push_back(od[i]);
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
        cout << endl;
    }

    return 0;
}
