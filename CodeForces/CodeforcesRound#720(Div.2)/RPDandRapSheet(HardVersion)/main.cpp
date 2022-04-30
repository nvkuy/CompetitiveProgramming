#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n, k;

void k_it(int a, vector<int> &arr_it) {
    if (a == 0)
        return;
    arr_it.push_back(a % k);
    k_it(a / k, arr_it);
}

int k_xor(int a, int b) {
    vector<int> ait, bit;
    k_it(a, ait), k_it(b, bit);
    int ans = 0, kp = 1;
    for (int i = 0; i < max(ait.size(), bit.size()); i++) {
        int tmp = 0;
        if (i < ait.size())
            tmp += ait[i];
        if (i < bit.size())
            tmp += bit[i];
        //cout << tmp % k << ' ';
        ans += (kp * (tmp % k));
        kp *= k;
    }
    return ans;
}

int k_xor_inv(int a, int b) {
    vector<int> ait, bit;
    k_it(a, ait), k_it(b, bit);
    int ans = 0, kp = 1;
    for (int i = 0; i < max(ait.size(), bit.size()); i++) {
        int tmp = 0;
        if (i < ait.size())
            tmp += (k - ait[i]);
        if (i < bit.size())
            tmp += bit[i];
        //cout << tmp % k << ' ';
        ans += (kp * (tmp % k));
        kp *= k;
    }
    return ans;
}

int query(int y) {
    cout << y << endl;
    cout.flush();
    int rp;
    cin >> rp;
    return rp;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            int y = k_xor_inv(tmp, i);
            int rp = query(y);
            tmp = k_xor(tmp, y);
            if (rp == -1)
                return 0;
            if (rp == 1)
                break;
        }
    }

    return 0;
}
