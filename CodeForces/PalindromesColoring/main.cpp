#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, k, dd[300];
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> c(k + 1, 0);
        memset(dd, 0, sizeof(dd));
        cin.ignore();
        getline(cin, s);
        for (int i = 0; i < n; i++)
            dd[(int)s[i]]++;
        int j = 1;
        for (int i = (int)'a'; i <= (int)'z'; i++) {
            while (dd[i] >= 2) {
                dd[i] -= 2;
                c[j] += 2;
                n -= 2;
                j %= k;
                j++;
            }
        }
        if (j > 1) {
            if ((j - 1) * 2 + n >= k)
                c[j]++;
        } else {
            if (n >= k)
                c[j]++;
        }
        cout << c[j] << endl;
    }

    return 0;
}
