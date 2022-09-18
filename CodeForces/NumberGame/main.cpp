#include <bits/stdc++.h>

using namespace std;

bool cnt(int n) {
    for (int i = 2; i * i <=  n; i++)
        if (!(n % i))
            return false;
    return true;
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        if (n % 2) {
            if (n == 1) {
                cout << "FastestFinger\n";
                continue;
            }
            cout << "Ashishgup\n";
        } else {
            if (n == 2) {
                cout << "Ashishgup\n";
                continue;
            }
            if ((int)pow(2, (int)log2(n)) == n) {
                cout << "FastestFinger\n";
                continue;
            }
            if (cnt(n / 2)) {
                cout << "FastestFinger\n";
                continue;
            }
            cout << "Ashishgup\n";
        }
    }

    return 0;
}
