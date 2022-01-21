#include <bits/stdc++.h>

using namespace std;

void dtk(long long n, vector<int> &kf, int i, int k) {
    if (n > 0) {
        kf[i] = n % k;
        dtk(n / k, kf, i - 1, k);
    }
}

int main()
{
    int t, n, k;
    long long x;
    string s, ans;
    cin >> t;
    while (t--) {
        s.clear(); ans.clear();
        cin >> n >> k >> x;
        cin.ignore();
        getline(cin, s);
        if (k == 0) {
            cout << s << endl;
            continue;
        }
        int c = 0;
        for (int i = 0; i < s.length(); i++)
            if (s[i] == '*')
                c++;
        vector<int> kf(c + 1, 0);
        dtk(x, kf, 31, k + 1);
        for (int i = 0; i <= c; i++)
            cout << kf[i] << ' ';
        cout << endl;
        k = 31;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '*')
                ans.push_back('a');
            else {
                for (int j = 0; j <= kf[k]; j++)
                    ans.push_back('b');
                if (k >= 31 - c)
                    k--;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
