#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, q, l, r;
    string s;
    cin >> n >> q;
    cin.ignore();
    vector<int> f(n + 1, 0);
    getline(cin, s);
    for (int i = 0; i < n; i++)
        f[i + 1] = f[i] + ((int)(s[i] - 'a') + 1);
    while (q--) {
        cin >> l >> r;
        cout << f[r] - f[l - 1] << endl;
    }

    return 0;
}
