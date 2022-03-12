#include <bits/stdc++.h>

using namespace std;

bool checkPrime(int x, int sk) {
    for (int i = 2; i * i <= x; i++) {
        if (i == sk)
            continue;
        if (x % i == 0)
            return false;
    }
    return true;
}

int main()
{

    int t, x, d;
    cin >> t;
    while (t--) {
        cin >> x >> d;
        int dc = 0;
        while (x % d == 0) {
            dc++;
            x /= d;
        }
        bool iok = true;
        if (checkPrime(x, 1)) {
            if (checkPrime(d, 1))
                iok = false;
            else {
                if (x * x == d && checkPrime(d, x) == true)
                    dc--;
                if (dc - 1 < 2)
                    iok = false;
            }
        } else {
            if (dc < 2)
                iok = false;
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
