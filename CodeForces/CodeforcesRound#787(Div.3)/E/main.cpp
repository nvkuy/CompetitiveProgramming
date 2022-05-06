#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, k;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cin.ignore();
        getline(cin, s);
        vector<int> dd(33, -2);
        for (int i = 0; i < n; i++) {
            if (k <= 0)
                break;
            int j = s[i] - 'a';
            if (dd[j] != -2)
                continue;
            while (j > 0 && k > 0 && dd[j] == -2) {
                dd[j] = j - 1;
                j--, k--;
            }
        }
        for (int i = 0; i < n; i++) {
            int j = s[i] - 'a';
            while (dd[j] >= 0)
                j = dd[j];
            s[i] = 'a' + j;
        }
        cout << s << endl;
    }

    return 0;
}
