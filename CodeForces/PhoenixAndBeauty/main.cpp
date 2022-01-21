#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, k, ai;
    set<int> s;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        s.clear();
        for (int i = 0; i < n; i++) {
            cin >> ai;
            s.insert(ai);
        }
        if (s.size() > k) {
            cout << "-1\n";
            continue;
        }
        cout << (n * k) << '\n';
        for (int i = 0; i < n; i++) {
            for (set<int>::iterator i = s.begin(); i != s.end(); i++)
                cout << *i << " ";
            for (int j = 0; j < (k - s.size()); j++)
                cout << "1 ";
        }
        cout << '\n';
    }
    return 0;
}
