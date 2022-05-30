#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int d,x,y;
void extEuclid(int A, int B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    } else {
        extEuclid(B, A % B);
        int temp = x;
        x = y;
        y = temp - (A / B) * y;
    }
}

int modInvEE(int A, int M) {
    extEuclid(A, M);
    return (x % M + M) % M;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, mul = 1, c = 0;
    cin >> n;
    vector<int> dd(n + 1, 0);
    for (long long i = 1; i < n; i++) {
        if (gcd(i, n) != 1)
            continue;
        mul = (mul * i) % n;
        dd[i] = 1, c++;;
    }
    while (mul % n != 1) {
        int rm = mul % n;
        dd[rm] = 0;
        mul = (mul * modInvEE(rm, n)) % n;
        c--;
    }
    cout << c << endl;
    for (int i = 0; i < n; i++)
        if (dd[i] == 1)
            cout << i << ' ';

    return 0;
}
