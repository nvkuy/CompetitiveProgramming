#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

long long modExpo(long long x, long long n, long long M){
    if(n == 0)
        return 1;
    else if(n % 2 == 0)
        return modExpo((x * x) % M, n / 2, M);
    else
        return (x * modExpo((x * x) % M, (n - 1) / 2, M)) % M;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    /*
    freopen("test.txt", "w", stdout);
    cout << "1 1000000000" << endl;
    for (char c = 'a'; c <= 'z'; c++)
        cout << c;
    return 0;
    freopen("test.txt", "r", stdin);
    */

    long long n, l, mod = 998244353, ans = 0;
    cin >> n >> l;
    cin.ignore();
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        getline(cin, arr[i]);
    for (int i = 0; i < (1 << n); i++) {
        bitset<18> bs(i);
        if (bs.count() == 0)
            continue;
        vector<int> cnt(55, 0);
        for (int j = 0; j < 18; j++) {
            if (!bs[j])
                continue;
            for (int k = 0; k < arr[j].length(); k++)
                cnt[arr[j][k] - 'a']++;
        }
        long long rva = 0, nb = bs.count();
        for (int k = 0; k < 55; k++)
            rva += (cnt[k] >= nb);
        long long tmp = modExpo(rva, l, mod);
        if (bs.count() % 2 == 0)
            tmp = -tmp;
        ans = (ans + tmp + mod) % mod;
    }
    cout << ans;

    return 0;
}
