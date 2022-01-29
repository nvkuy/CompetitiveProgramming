#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, tt;
    string n, a, b;
    cin >> t;
    while (t--) {
        cin >> tt;
        if (tt < 10) {
            cout << tt - 1 << endl;
            continue;
        }
        n = to_string(tt);
        a.clear(); b.clear();
        for (int i = 0; i < n.length(); i++) {
            if (i % 2)
                a.push_back(n[i]);
            else
                b.push_back(n[i]);
        }
        int c1 = stoi(a), c2 = stoi(b);
        cout << (long long)((c1 + 1) * (c2 + 1)) - 2 << endl;
    }

    return 0;
}
