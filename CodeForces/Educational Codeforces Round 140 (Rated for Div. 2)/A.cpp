#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {
        vector<int> x(3), y(3);
        for (int i = 0; i < 3; i++)
            cin >> x[i] >> y[i];
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        if (x[1] != x[0] && x[1] != x[2]) {
            cout << "YES" << endl;
            continue;
        }
        if (y[1] != y[0] && y[1] != y[2]) {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }

    return 0;
}