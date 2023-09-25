#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> primes, isPrime(2e5 + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= 2e5; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= 2e5; j += i)
                isPrime[j] = 0;
        }
    }
    for (int i = 0; i <= 2e5; i++)
        if (isPrime[i]) primes.push_back(i);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    map<int, map<int, int>> cnt;
    for (int i = 0; i < n; i++) {
        int ai = a[i];
        map<int, int> tmp;
        for (int j : primes) {
            if (j * j > ai) break;
            int c = 0;
            while (ai % j == 0) {
                c++;
                ai /= j;
            }
            tmp[j] = c;
        }
        if (ai > 1)
            tmp[ai] = 1;
        for (auto p : tmp) {
            for (int k = 0; k <= p.second; k++)
                cnt[p.first][k]++;
        }
    }

    long long res = 1;
    for (long long num : primes) {
        for (int j = 1; j < 60; j++) {
            int not_have = n - cnt[num][j];
            if (not_have > 1) break;
            res *= num;
        }
    }

    cout << res << endl;

    return 0;

}