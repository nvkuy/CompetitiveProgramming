#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

int cal(int n, int m) {
    if (n < m)
        swap(n, m);
    if (n < 3)
        return (((n * m) / 2) + ((n * m) % 2));
    else
        return ((m * (n / 3)) + cal(n % 3, m));
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cout << cal(n, m) << endl;
    }

    return 0;
}
