#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

long long k;
vector<int> a, ans;

void cal(long long x) {
    long long tmp = 1, p;
    for (p = 0; p < a.size(); p++) {
        if (tmp >= (2e18 / a[p]))
            break;
        tmp *= a[p];
        if (tmp >= x) {
            tmp /= a[p];
            break;
        }
    }
    while (x > 1) {
        ans[p] = max(((x / tmp) + (x % tmp > 0)), 1LL);
        x -= ((ans[p] - 1LL) * tmp);
        p--;
        if (p >= 0)
            tmp /= a[p];
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    long long n, x;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> k >> x;
        cin.ignore();
        getline(cin, s);
        a.clear(); ans.clear();
        for (int i = 0; i < n; i++) {
            if (s[i] != '*')
                continue;
            if (i == 0 || s[i - 1] != '*')
                a.push_back(k);
            else
                a.back() += k;
        }
        for (int i = 0; i < a.size(); i++)
            a[i]++;
        reverse(a.begin(), a.end());
        ans.assign(a.size(), 1);
        cal(x);
        for (int i = 0; i < n; i++) {
            if (s[i] != '*') {
                cout << 'a';
                continue;
            }
            if (i == 0 || s[i - 1] != '*') {
                for (int j = 1; j < ans.back(); j++)
                    cout << 'b';
                ans.pop_back();
            }
        }
        cout << endl;
    }

    return 0;
}
