#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, ai;
    cin >> t;
    while (t--) {
        cin >> n;
        set<int> s;
        for (int i = 0; i < n; i++) {
            cin >> ai;
            s.insert(ai);
        }
        int tp = s.size();
        for (int i = 1; i <= n; i++)
            cout << max(tp, i) << ' ';
        cout << endl;
    }

    return 0;
}
