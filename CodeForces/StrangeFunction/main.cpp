#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

int main()
{
    int t;
    long long n;
    vector<long long> a;
    a.push_back(1);
    for (int i = 2; i <= 100; i++) {

    }

    cin >> t;


    return 0;
}
