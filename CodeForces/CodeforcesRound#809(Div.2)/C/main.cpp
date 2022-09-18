#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n;
vector<int> a;

void buildPS(int pos, vector<long long> &ps) {
    ps.clear();
    for (int i = 0; i < pos; i++)
        ps.push_back(0LL);
    long long ans = 0;
    for (int i = pos; i < n; i++) {
        if (((i - pos) % 2 == 1) || (i + 1 >= n)) {
            ps.push_back(ans);
            continue;
        }
        long long need_height = max(a[i - 1], a[i + 1]);
        if (need_height >= a[i])
            ans += (need_height - a[i] + 1);
        ps.push_back(ans);
    }
}

long long costLR(int l, int r, vector<long long> &psOdd, vector<long long> &psEven) {
    if (l % 2)
        return psOdd[r] - psOdd[l - 1];
    return psEven[r] - psEven[l - 1];
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
        vector<long long> psOdd, psEven;
        buildPS(1, psOdd);
        buildPS(2, psEven);
        int potential = n - 2;
        if (potential % 2) {
            cout << costLR(1, n - 1, psOdd, psEven) << endl;
            continue;
        }
        long long ans = 1e18;
        for (int i = 0; i < n; i += 2) {
            int pickL = i - 1, pickR = i + 2;
            long long tans = 0;
            if (pickL > 0) {
                if (pickL % 2)
                    tans += costLR(1, pickL, psOdd, psEven);
                else
                    tans += costLR(2, pickL, psOdd, psEven);
            }
            if (pickR < n)
                tans += costLR(pickR, n - 1, psOdd, psEven);
            ans = min(ans, tans);
        }
        cout << ans << endl;
    }

    return 0;
}
