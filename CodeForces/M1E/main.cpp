#include <bits/stdc++.h>

using namespace std;

long long a, b, c, m;
int d, x, y;
void extendedEuclid(int A, int B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}
int modInverse(int A, int M)
{
    extendedEuclid(A,M);
    return (x%M+M)%M;
}

long long cpow(long long a, long long b) {

    long long ans = 1;
    while (b > 0) {
        if (b % 2 == 1)
            ans = ((ans * a) % m);
        a = ((a * a) % m);
        b = b / 2;
    }

    return ans;
}

int main()
{

    cin >> a >> b >> c >> m;
    cout << (((cpow(a, b) % m) * (modInverse(c, m) % m)) % m);

    return 0;
}
