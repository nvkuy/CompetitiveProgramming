#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t, n, ai;
    long long s;
    cin >> t;
    while (t--) {
        cin >> n;
        s = 0;
        for (int i = 0; i < n; i++) {
            cin >> ai;
            s += ai;
        }
        cout << min((int)(s % n), 1) << endl;
    }

    return 0;
}
