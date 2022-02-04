#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, ai;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            cin >> ai;
            if (ai == 1)
                ans.push_back(ai);
            else {
                int j = 1;
                while (j < ai)
                    j *= 2;
                if (j > ai)
                    j /= 2;
                ans.push_back(j);
            }
        }
        for (int i = 0; i < n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }

    return 0;
}
