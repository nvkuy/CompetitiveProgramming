#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

vector<int> a;
int n;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int cal(int i1, int i2) {
    int diff = a[i2] - a[i1], d = i2 - i1;
    int rd = gcd(d, abs(diff));
    d /= rd, diff /= rd;
    int k = i1 / d, sti = i1 % d, ca = a[i1] - k * diff, co = 0;
    for (int i = sti; i < n; i += d) {
        if (a[i] == ca)
            co++;
        ca += diff;
    }
    return n - co;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int ans = n - 1;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                ans = min(ans, cal(i, j));
        cout << ans << endl;
    }

    return 0;
}
