#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        if ((n + m) > 2) {
            if (n == 1 || m == 1)
                cout << "1\n"; //1 hang thi dat dau hang
            else
                cout << "2\n"; //nhieu hang thi dat hang 1, hang n
        } else
            cout << "0\n"; // 1 o thi k can dat
    }

    return 0;
}
