#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long maxN = 4 * 1e4 + 1, mod = 1e9 + 7;
    vector<int> pn;
    for (int i = 1; i <= 9; i++) {
        pn.push_back(i);
        pn.push_back(i * 10 + i);
        for (int j = 0; j <= 9; j++) {
            pn.push_back(i * 100 + j * 10 + i);
            int tmp = i * 1000 + j * 100 + j * 10 + i;
            if (tmp < maxN)
                pn.push_back(tmp);
            for (int k = 0; k <= 9; k++) {
                int temp = i * 10000 + j * 1000 + k * 100 + j * 10 + i;
                if (temp < maxN)
                    pn.push_back(temp);
            }
        }
    }
    sort(pn.begin(), pn.end());
    //cout << pn.size() << endl;
    vector<long long> f(4 * 1e4 + 1, 0);
    f[0] = 1;
    for (int j = 1; j <= pn.size(); j++) {
        for (int i = 1; i < maxN; i++) {
            if (i >= pn[j - 1])
                f[i] = (f[i] + f[i - pn[j - 1]]) % mod;
        }
    }
    /*
    for (int i = 1; i <= 100; i++)
        cout << f[i] << ' ';
    */

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << f[n] << endl;
    }

    return 0;
}
