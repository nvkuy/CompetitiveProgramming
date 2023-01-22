#include <bits/stdc++.h>
using namespace std;

void sieve(int n, vector<int> &isPrime) {
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

int main() {

    vector<int> isPrime;
    sieve(1e5, isPrime);
    vector<int> primes;
    for (int i = 0; i < 1e5; i++)
        if (isPrime[i]) primes.push_back(i);
    int t, n, ai;
    cin >> t;
    while (t--) {
        cin >> n;
        set<int> dd;
        bool iok = false;
        while (n--) {
            cin >> ai;
            if (iok)
                continue;
            for (int pi : primes) {
                if (iok || ai < 2)
                    break;
                if (ai % pi == 0) {
                    if (dd.find(pi) != dd.end()) 
                        iok = true;
                    dd.insert(pi);
                    while (ai % pi == 0)
                        ai /= pi;
                }
            }
            if (ai > 1) {
                if (dd.find(ai) != dd.end())
                    iok = true;
                dd.insert(ai);
            }
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}