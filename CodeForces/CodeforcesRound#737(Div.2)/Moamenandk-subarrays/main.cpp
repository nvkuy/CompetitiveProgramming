#include <bits/stdc++.h>

using namespace std;

set<int> s;
set<int>::iterator it;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> a(n);
        s.clear();
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s.insert(a[i]);
        }
        int i = 0;
        while (i < n) {
            it = s.find(a[i]);
            k--;
            while ((*it) == a[i]) {
                i++;
                it++;
                if (i == n)
                    break;
                if (it == s.end())
                    break;
            }
        }
        cout << ((k >= 0) ? "YES" : "NO") << endl;
    }

    return 0;
}
