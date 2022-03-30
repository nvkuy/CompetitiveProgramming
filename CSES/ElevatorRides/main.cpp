#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n;
vector<int> w;

long long cal(bitset<22> choose) {
    long long ans = 0LL;
    for (int i = 0; i < n; i++)
        ans += (choose[i] * w[i]);
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int x, fm = (1 << n);
    cin >> n >> x;
    w.resize(n);
    for (int i = 0; i < n; i++)
        cin >> w[i];
    vector<vector<bool>> f(22, vector<bool>(fm, false));
    for (int i = 0; i <= n; i++)
        f[i][0] = true;
    bool iok = false;
    for (int j = 1; j <= n; j++) {
        for (int i = 0; i < fm; i++) {
            int rm = ((fm - 1) ^ i);
            bitset<22> choose(i), rem(rm);
            if (cal(choose) > x)
                continue;
            vector<int> rmi;
            for (int k = 0; k < n; k++) {
                if (rem[i])
                    rmi.push_back(i);
            }
            for (int k = 0; k < (1 << rmi.size()); k++) {
                bitset<22> prermbs(k);
                int prerm = 0;
                for (int l = 0; l < rmi.size(); l++) {
                    if (prermbs[l])
                        prerm ^= (1 << rmi[l]);
                }
                if (f[j - 1][prerm])
                    f[j][i ^ prerm] = true;
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        if (f[i][fm - 1]) {
            cout << i;
            return 0;
        }
    }

    return 0;
}
