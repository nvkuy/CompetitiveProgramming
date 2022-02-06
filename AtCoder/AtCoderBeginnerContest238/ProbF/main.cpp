#include <bits/stdc++.h>

using namespace std;

long long modExpo(long long x, long long n, long long M){
    if(n == 0)
        return 1;
    else if(n % 2 == 0)
        return modExpo((x * x) % M, n / 2, M);
    else
        return (x * modExpo((x * x) % M, (n - 1) / 2, M)) % M;
}

int modInvFE(int A,int M) {
    return modExpo(A,M-2,M);
}

long long cal(vector<pair<int, int>> a, long long n, long long k, long long mod) {
    vector<bool> dd(n, false);
    sort(a.begin(), a.end());
    long long c = 0LL;
    for (int i = 0; i < n; i++) {
        if (i < k) {
            c++;
            dd[i] = true;
        } else {
            for (int j = 0; j < i; j++) {
                if ((a[j].second > a[i].second) && (dd[j])) {
                    c++;
                    dd[i] = true;
                    break;
                }
            }
        }
    }
    //cout << "CHECK: " << c << endl;
    long long f1 = 1LL, f2 = 1LL;
    for (long long i = c - k + 1LL; i <= c; i++)
        f1 = (f1 * i) % mod;
    for (long long i = 1LL; i <= k; i++)
        f2 = (f2 * i) % mod;
    return (f1 * modInvFE(f2, mod)) % mod;
}

int main()
{
    long long n, k, c, mod = 998244353, ans;
    cin >> n >> k;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        cin >> c;
        a.push_back(make_pair(c, 0));
    }
    for (int i = 0; i < n; i++) {
        cin >> c;
        a[i].second = c;
    }
    ans = cal(a, n, k, mod);
    /*
    for (int i = 0; i < n; i++)
        swap(a[i].first, a[i].second);
    ans = (ans + cal(a, n, k, mod)) % mod;
    */
    cout << ans;

    return 0;
}
