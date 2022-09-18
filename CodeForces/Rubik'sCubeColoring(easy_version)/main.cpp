#include <bits/stdc++.h>

using namespace std;

long long mod = 1e9 + 7;

long long binaryExponentiation(long long x, long long n){
    long long result = 1;
    while(n > 0) {
        if(n % 2 == 1)
            result = ((result % mod) * (x % mod)) % mod;
        x = ((x % mod) * (x % mod)) % mod;
        n = n / 2;
    }
    return result % mod;
}

int main()
{
    long long k;
    cin >> k;
    cout << ((6 * binaryExponentiation(4, (long long)(pow(2, k) - 2))) % mod) << endl;

    return 0;
}
