#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<long long> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int q;
    cin >> q;
    
    while (q--) {
        long long i, j;
        cin >> i >> j;
        vector<long long> b = a;
        b[i] = j;
        sort(b.begin(), b.end());
        long long ans = 0;
        for (long long i = 1; i <= n; i++)
            ans += (b[i] * i);
        cout << ans << endl;
    }

    return 0;
}
