#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << (1LL << n) - 1LL << endl;
    }

    return 0;
}
