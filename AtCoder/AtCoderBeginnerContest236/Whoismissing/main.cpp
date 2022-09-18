#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, ai, s;
    cin >> n;
    s = 0LL;
    n = 4 * n - 1;
    while (n--) {
        cin >> ai;
        s ^= ai;
    }
    cout << s;

    return 0;
}
