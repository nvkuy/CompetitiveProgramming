#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t, n, ai;
    set<int> s;
    cin >> t;
    while (t--) {
        cin >> n;
        s.clear();
        for (int i = 0; i < n; i++) {
            cin >> ai;
            if (s.find(ai) != s.end())
                s.insert(-ai);
            else
                s.insert(ai);
        }
        cout << s.size() << endl;
    }

    return 0;
}
