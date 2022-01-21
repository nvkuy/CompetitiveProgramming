#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, a, b;
    vector<int> ans;
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        if ((a + b + 2) > n || (abs(a - b) > 1)) {
            cout << -1 << endl;
            continue;
        }
        /*
        if (a == 0 && b == 0) {
            for (int i = 1; i <= n; i++)
                cout << i << " ";
            cout << endl;
            continue;
        }
        */
        int i = n, j = 1;
        ans.clear();
        if (a <= b) {
            while (i >= j) {
                ans.push_back(i);
                i--;
                if ((n % 2) && (i <= j))
                    break;
                ans.push_back(j);
                j++;
            }
            if (a == b)
                sort(ans.begin() + a + b, ans.end(), greater<int>());
            else
                sort(ans.begin() + a + b + 1, ans.end());
        } else {
            while (i >= j) {
                ans.push_back(j);
                j++;
                if ((n % 2) && (i <= j))
                    break;
                ans.push_back(i);
                i--;
            }
            sort(ans.begin() + a + b + 1, ans.end(), greater<int>());
        }
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}
