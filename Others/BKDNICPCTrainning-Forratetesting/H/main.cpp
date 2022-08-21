#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int maxN = 3e8 + 1;

bitset<maxN> notPrime(0);

void sieve() {
    notPrime[0] = 1;
    notPrime[1] = 1;
    for(int i = 2; i * i < maxN; ++i) {
         if(notPrime[i] == 0) {
             for(int j = i * i; j < maxN; j += i)
                 notPrime[j] = 1;
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    sieve();

    long long l, r, ans = 0;
    cin >> l >> r;
    for (int i = 1; i * i <= r; i++) {
        for (int j = i; j * j <= r; j++) {
            int num = i * i + j * j;
            if (num >= l && num <= r && notPrime[num] == 0) {
                ans++;
                //cout << i << '|' << j << '|' << num << endl;
            }
        }
    }
    cout << ans;

    return 0;
}
