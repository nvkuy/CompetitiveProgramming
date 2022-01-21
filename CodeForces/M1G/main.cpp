#include <bits/stdc++.h>

using namespace std;

long long gt[1000004];
int mod = 1e6 + 3;

int main()
{
    gt[0] = 1;
    for (int i = 1; i <= mod; i++)
        gt[i] = (i * gt[i - 1]) % mod;

    gt[0] = gt[mod];
    int t;
    long long n, x;
    cin >> t;
    while (t > 0) {
        t--;
        cin >> n >> x;
        if (n >= mod)
            cout << "0";
        else
            cout << (gt[n] * (x % mod)) % mod;
        cout << "\n";
    }

    return 0;
}
