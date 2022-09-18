#include <bits/stdc++.h>

using namespace std;

deque<int> a;
//vector<int>::iterator it;
bool dd[100001];

int main()
{
    int t, n, ai;
    cin >> t;
    while (t--) {
        cin >> n;
        memset(dd, false, sizeof(dd));
        a.clear();
        for (int i = 0; i < n; i++) {
            cin >> ai;
            if (ai > n) {
                a.push_back(ai);
                continue;
            }
            if (!dd[ai])
                dd[ai] = true;
            else
                a.push_back(ai);
        }
        int ans = 0;
        sort(a.begin(), a.end());
        for (int i = 1; i <= n; i++) {
            if (dd[i])
                continue;
            if (a.empty()) {
                ans = -1;
                break;
            } else {
                while (a.front() <= (2 * i) && a.size() > 1)
                    a.pop_front();
                if (a.front() <= (2 * i)) {
                    ans = -1;
                    break;
                } else {
                    ans++;
                    a.pop_front();
                }
            }
            /*
            it = upper_bound(a.begin(), a.end(), 2 * i);
            if (it == a.end()) {
                ans = -1;
                break;
            } else {
                ans++;
                a.erase(it);
            }
            */
        }
        cout << ans << endl;
    }

    return 0;
}
