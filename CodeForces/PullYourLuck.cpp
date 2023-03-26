#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {
        long long n, x, p;
        cin >> n >> x >> p;
        long long tmp = (n - ((4LL * x) % n)) % n;
        bool iok = false;
        for (long long i = 1; i <= n; i++) {
            if (i > p) break;
            if ((i * ((i + 1LL) % n)) % n == tmp) {
                iok = true;
                break;
            }
        }
        cout << (iok ? "Yes" : "No") << endl;
    }

    return 0;
}