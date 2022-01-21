#include <bits/stdc++.h>

using namespace std;

bool isPN(int n) {
    if (n <= 1)
        return false;
    int ans = 1, j = 2, c = 0, m = n;
    while (m >= j) {
        c = 0;
        while (m % j == 0) {
            c++;
            m /= j;
        }
        ans *= ((pow(j, c + 1) - 1) / (j - 1));
        j++;
    }
    if (m != 1)
        ans *= 2;
    return ((ans - n) == n);
}

int main()
{
    int n, t;
    cin >> t;
    while (t > 0) {
        t--;
        cin >> n;
        cout << isPN(n) << "\n";
    }

    return 0;
}
