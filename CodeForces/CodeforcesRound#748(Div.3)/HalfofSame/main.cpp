#include <bits/stdc++.h>

using namespace std;
/*
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
*/
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0); cout.tie(0);
    int t, n, ans;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        set<int> mn;
        set<int>::reverse_iterator it;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        int eq;
        for (int i = 0; i < n; i++) {
            eq = 0;
            for (int j = 0; j < n; j++)
                if (a[i] == a[j])
                    eq++;
            if (eq >= (n / 2))
                break;
        }
        if (eq >= (n / 2)) {
            cout << "-1\n";
            continue;
        }
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j > i; j--) {
                //if (mn.find(a[j] - a[i]) != mn.end())
                //    continue;
                for (int k = 1; (k * k) <= (a[j] - a[i]); k++) {
                    if ((a[j] - a[i]) % k == 0) {
                        mn.insert(k);
                        mn.insert((a[j] - a[i]) / k);
                    }
                }
            }
        }
        //ans = 1;
        for (it = mn.rbegin(); it != mn.rend(); it++) {
            //cout << "TEST: " << (*it) << endl;
            bool iok = false;
            for (int j = 0; j < n; j++) {
                int co = 0;
                for (int k = j; k < n; k++) {
                    if ((a[k] - a[j]) % (*it) == 0)
                        co++;
                    if (co >= n / 2)
                        break;
                }
                if (co >= n / 2)
                    iok = true;
            }
            if (iok) {
                ans = (*it);
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
