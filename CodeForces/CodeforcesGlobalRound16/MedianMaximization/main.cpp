#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, s;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        n += 2;
        n /= 2;
        if (n == 0)
            cout << s << endl;
        else {
            cout << s / n << endl;
        }
    }

    return 0;
}
