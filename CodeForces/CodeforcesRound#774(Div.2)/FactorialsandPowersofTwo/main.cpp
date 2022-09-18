#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    long long n, ans, tans, tmp;
    vector<long long> facs;
    ans = 2LL, n = 3LL;
    while ((ans * n) <= 1e12) {
        ans *= n;
        n++;
        facs.push_back(ans);
    }
    cin >> t;
    while (t--) {
        cin >> n;
        ans = 1e18;
        for (int cf = 0; cf < pow(2LL, facs.size()); cf++) {
            bitset<20> cfacs(cf);
            tmp = n;
            tans = 0LL;
            for (int i = 0; i < facs.size(); i++) {
                if (cfacs[i]) {
                    tmp -= facs[i];
                    tans++;
                }
            }
            bitset<64> rm(tmp);
            for (int i = 0; i < 64; i++)
                tans += rm[i];
            ans = min(ans, tans);
        }
        cout << ans << endl;
    }

    return 0;
}
