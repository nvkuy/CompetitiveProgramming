#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

int n;
vector<int> a, b;

bool check(int k) {
    int r = k - k / 4, ar = k - n;
    int p1 = min(ar, r) * 100, p2 = 0, t1 = max(r - ar, 0), t2 = r;
    for (int i = 0; i < n; i++) {
        if (t1 > 0) {
            p1 += a[i];
            t1--;
        }
        if (t2 > 0) {
            p2 += b[i];
            t2--;
        }
    }
    return p1 >= p2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        a.resize(n), b.resize(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());
        int l = n, r = 1e7, m;
        while (l < r) {
            m = (l + r) / 2;
            if (check(m))
                r = m;
            else
                l = m + 1;
        }
        cout << l - n << endl;
    }

    return 0;
}
