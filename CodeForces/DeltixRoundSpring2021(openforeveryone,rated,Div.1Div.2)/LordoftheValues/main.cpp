#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

void make(int i, int j) {
    cout << "1 " << i << ' ' << j << '\n';
    cout << "2 " << i << ' ' << j << '\n';
    cout << "2 " << i << ' ' << j << '\n';
    cout << "1 " << i << ' ' << j << '\n';
    cout << "2 " << i << ' ' << j << '\n';
    cout << "2 " << i << ' ' << j << '\n';
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << 6 * (n / 2) << '\n';
        for (int i = 0; i < n; i+=2)
            make(i + 1, i + 2);
    }

    return 0;
}
