#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int ps[200002], n;

int f(int l, int r) {
    //xoa con lai l -> r
    if (l > r)
        return ps[n];
    int numZeroRem = n - ps[n], numOneDel = 0;
    numOneDel += ps[l - 1], numZeroRem -= (l - 1 - ps[l - 1]);
    numOneDel += (ps[n] - ps[r]), numZeroRem -= (n - r - ps[n] + ps[r]);
    return max(numOneDel, numZeroRem);
}

bool checkCost(int cost) {
    for (int i = 0; i <= n; i++) {
        // xoa tu 1 -> i
        int l = i, r = n, m;
        while (l < r) {
            if (r - l == 1) {
                if (r - i - ps[r] + ps[i] <= cost)
                    l = r;
                break;
            }
            m = (l + r) / 2;
            if (m - i - ps[m] + ps[i] > cost)
                r = m - 1;
            else
                l = m;
        }
        if (f(i + 1, l) <= cost)
            return true;
    }
    return false;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    string s;
    cin >> t;
    cin.ignore();
    while (t--) {
        getline(cin, s);
        n = s.length();
        ps[0] = 0;
        for (int i = 0; i < n; i++)
            ps[i + 1] = ps[i] + (s[i] - '0');
        int l = 0, r = n, m;
        while (l < r) {
            m = (l + r) / 2;
            if (checkCost(m))
                r = m;
            else
                l = m + 1;
        }
        cout << l << endl;
    }

    return 0;
}
