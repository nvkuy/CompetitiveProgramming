#include <bits/stdc++.h>
using namespace std;

int rand_range(int l, int r) {
    return l + (rand() % (r - l + 1));
}

int main()
{

    srand((int) time(0));
    int n = 10, max_val = 10, q = 10;
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << rand_range(0, max_val) << ' ';
    }
    cout << endl;
    cout << q << endl;
    while (q--) {
        cout << rand_range(1, n) << ' ' << rand_range(0, max_val) << endl;
    }

    return 0;
}
