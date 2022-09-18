#include <bits/stdc++.h>

using namespace std;

bool checkPrime(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i = a; i <= b; i++) {
        bool iok = false;
        for (int j = c; j <= d; j++) {
            if (checkPrime(i + j)) {
                iok = true;
                break;
            }
        }
        if (!iok) {
            cout << "Takahashi";
            return 0;
        }
    }
    cout << "Aoki";

    return 0;
}
