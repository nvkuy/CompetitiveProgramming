#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {
        long long n, x, p;
        cin >> n >> x >> p;
        bool iok = false;
        for (long long i = 1; i <= 2 * n; i++) {
            if (i > p) break;
            long long tmp = (i * (i + 1LL) / 2LL) - (n - x);
            if ((tmp >= 0) && (tmp % n == 0)) {
                iok = true;
                break;
            }
        }
        cout << (iok ? "Yes" : "No") << endl;
    }

    return 0;
}