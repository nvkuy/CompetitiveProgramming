#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    /*
    //GEN TEST
    srand(time(NULL));
    freopen("TEST_INP.txt", "w", stdout);
    int tt = (rand() % (int)100) + 1;
    cout << tt << '\n';
    while (tt--) {
        int tn = (rand() % (int)1000) + 1;
        cout << tn << ' ' << (rand() % (int)1e6) + 1 << '\n';
        for (int i = 0; i < tn; i++)
            cout << (rand() % (int)1e9) + 1 << ' ';
        cout << '\n';
    }
    */

    /*
    //TESTING
    freopen("TEST_INP.txt", "r", stdin);
    long long t, n, x, tx;
    cin >> t;
    vector<int> ans(t, 0);
    while (t--) {
        cin >> n >> x;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        while (x >= a[0]) {
            tx = x;
            for (int j = 0; j < n; j++) {
                if (tx >= a[j]) {
                    ans[t]++;
                    tx -= a[j];
                } else
                    break;
                a[j]++;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    freopen("TEST_OUT.txt", "r", stdin);
    for (int i = 0; i < ans.size(); i++) {
        cin >> x;
        if (x != ans[i])
            cout << "WRONG ANSWER ON TEST " << i << ' ' << x << '|' << ans[i] << '\n';
    }
    */

    //freopen("TEST_INP.txt", "r", stdin);
    //freopen("TEST_OUT.txt", "w", stdout);
    long long t, n, x;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        vector<long long> ps;
        ps.push_back(a[0]);
        for (int i = 1; i < n; i++)
            ps.push_back(ps[i - 1] + a[i]);
        long long ans = 0, d = 0, td;
        for (long long i = n - 1; i >= 0; i--) {
            td = (x - d * (i + 1) - ps[i]);
            if (td < 0)
                continue;
            td /= (i + 1);
            td++;
            ans += ((i + 1) * td);
            d += td;
            //cout << ps[i] << '|' << td << '|' << d << '|' << ans << endl;
        }
        cout << ans << endl;
    }

    return 0;
}
