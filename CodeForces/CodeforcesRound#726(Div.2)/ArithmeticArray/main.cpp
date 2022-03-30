#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t, n, s, ai;
    cin >> t;
    while (t--) {
        cin >> n;
        s = 0;
        for (int i = 0; i < n; i++) {
            cin >> ai;
            s += ai;
        }
        if (s < n)
            cout << "1\n";
        else
            cout << s - n << endl;
    }

    return 0;
}
