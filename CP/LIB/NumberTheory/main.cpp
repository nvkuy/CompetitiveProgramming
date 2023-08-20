#include <bits/stdc++.h>

#define bit_cnt(x) __builtin_popcountll(x)

using namespace std;

vector<int> primes;

long long phi(long long n, long long m) { // count number k that gcd(n, k) == 1 and k <= m
    vector<int> fac;
    for (int p : primes) {
        if (p * p > n) break;
        if (n % p == 0) {
            fac.push_back(p);
            while (n % p == 0) n /= p;
        }
    }
    if (n > 1) fac.push_back(n);
    int prime_cnt = fac.size();
    long long cnt = 0;
    for (int i = 1; i < (1 << prime_cnt); i++) {
        long long lcm_mask = 1;
        for (int j = 0; j < prime_cnt; j++) {
            if ((i >> j) & 1)
                lcm_mask = min(m + 1, lcm_mask * fac[j]);
        }
        cnt += (m / lcm_mask) * (bit_cnt(i) % 2 ? 1 : -1);
    }
    return m - cnt;
}

// count x <= m: gcd(a[i - 1], x) = a[i] 
// => (a[i - 1] % a[i] == 0 && x % a[i] == 0) 
// => count x <= m: gcd(a[i - 1] / a[i], x / a[i]) = 1
long long cal(long long pre_a, long long cur_a, long long m) {
    if (pre_a % cur_a > 0) return 0;
    return phi(pre_a / cur_a, m / cur_a);
}

long long modExpo(long long x, long long n, long long M){
    if(n == 0)
        return 1;
    else if(n % 2 == 0)
        return modExpo((x * x) % M, n / 2, M);
    else
        return (x * modExpo((x * x) % M, (n - 1) / 2, M)) % M;
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

//gcd(A, M) == 1
int modInvEE(int A, int M) {
    extEuclid(A, M);
    return (x % M + M) % M;
}
//isPrime(M) == true
int modInvFE(int A,int M) {
    return modExpo(A,M-2,M);
}

void sieve(int n, vector<bool> &isPrime) {
    isPrime.assign(n + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i * i <= n; ++i) {
         if(isPrime[i] == true) {
             for(int j = i * i; j <= n; j += i)
                 isPrime[j] = false;
        }
    }
}

void facSieve(int n, vector<int> &minPrime) {
    minPrime.assign(n + 1, 0);
    for (int i = 2; i * i <= n; ++i) {
        if (minPrime[i] == 0) {
            for (int j = i * i; j <= n; j += i) {
                if (minPrime[j] == 0) {
                    minPrime[j] = i;
                }
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (minPrime[i] == 0) {
            minPrime[i] = i;
        }
    }
}

vector<int> factorize(int n, vector<int> &minPrime) {
    vector<int> res;
    while (n != 1) {
        res.push_back(minPrime[n]);
        n /= minPrime[n];
    }
    return res;
}

void rangeSieve(int L, int R, vector<bool> &isPrime) {
    isPrime.assign(R - L + 1, true);
    for (long long i = 2; i * i <= R; ++i) {
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i) {
            isPrime[j - L] = false;
        }
    }
    if (1 >= L) {
        isPrime[1 - L] = false;
    }
}

int xorOneToN(int n) {
    if (n % 4 == 0)
        return n;
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    return 0;
}

int main()
{

    cout << modExpo(2, 1000, 1e9 + 7) << endl;

    cout << modInvEE(2, 1e9 + 7) << endl;

    cout << modInvFE(2, 1e9 + 7) << endl;

    vector<bool> isPrime;
    sieve(1e6, isPrime);
    for (int i = 0; i <= 10; i++) {
        if (isPrime[i])
            cout << i << ' ';
    }
    cout << endl;

    vector<int> minPrime, facs;
    facSieve(1e6, minPrime);
    facs = factorize(100, minPrime);
    for (int i = 0; i < facs.size(); i++)
        cout << facs[i] << ' ';
    cout << endl;

    vector<bool> rgSieve;
    int L = 1e7, R = 1e7 + 1e4;
    rangeSieve(L, R, rgSieve);
    for (long long x = L; x <= R; ++x) {
        if (rgSieve[x - L]) {
            cout << x << ' ';
        }
    }
    cout << endl;

    return 0;
}
