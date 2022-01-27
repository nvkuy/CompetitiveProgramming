#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    long long a, b, n, tmp;
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        vector<long long> ma;
        tmp = 1;
        while (tmp <= n) {
            ma.push_back(tmp);
            tmp *= a;
            if (a == 1)
                break;
        }
        bool iok = false;
        for (int i = 0; i < ma.size(); i++) {
            if ((n - ma[i]) % b == 0) {
                iok = true;
                break;
            }
        }
        cout << (iok ? "YES" : "NO") << '\n';
    }

    return 0;
}
