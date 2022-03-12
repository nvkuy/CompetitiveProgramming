#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int st;
        if (n % 3 == 0 || n % 3 == 2)
            st = 2;
        else
            st = 1;
        while (n > 0) {
            cout << st;
            n -= st;
            st = 3 - st;
        }
        cout << endl;
    }

    return 0;
}
