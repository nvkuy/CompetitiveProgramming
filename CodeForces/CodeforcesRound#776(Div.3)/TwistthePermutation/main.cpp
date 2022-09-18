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
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            cin >> ai;
            dq.push_back(ai);
        }
        for (int i = n; i > 0; i--) {
            int d, tmp;
            for (int j = 0; j < i; j++) {
                if (dq[j] == i) {
                    d = j + 1;
                    break;
                }
            }
            ans.push_back((d == i ? 0 : d));
            for (int j = i - 1; j >= d; j--) {
                tmp = dq.back();
                dq.pop_back();
                dq.push_front(tmp);
            }
            dq.pop_back();
        }
        for (int i = n - 1; i >= 0; i--)
            cout << ans[i] << ' ';
        cout << endl;
    }

    return 0;
}
