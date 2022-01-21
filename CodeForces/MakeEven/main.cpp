#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t, n;
    bool da;
    string s;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        if (n % 2 == 0) {
            cout << "0\n";
            continue;
        }
        s = to_string(n);
        if ((s[0] - '0') % 2 == 0) {
            cout << "1\n";
        } else {
            da = false;
            for (int i = 1; i < s.length(); i++) {
                if ((s[i] - '0') % 2 == 0) {
                    cout << "2\n";
                    da = true;
                    break;
                }
            }
            if (!da)
                cout << "-1\n";
        }
    }

    return 0;
}
