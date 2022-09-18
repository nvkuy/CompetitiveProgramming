#include <bits/stdc++.h>

using namespace std;

int minPrime[1000001], c[1000001];

int main()
{
    memset(minPrime, 0, sizeof(minPrime));
    memset(c, 0, sizeof(c));
    for (int i = 2; i * i <= 1000000; ++i) {
        if (minPrime[i] == 0) {
            for (int j = i * i; j <= 1000000; j += i) {
                if (minPrime[j] == 0) {
                    minPrime[j] = i;
                }
            }
        }
    }
    for (int i = 2; i <= 1000000; ++i) {
        if (minPrime[i] == 0) {
            minPrime[i] = i;
        }
        c[minPrime[i]]++;
    }
    int t, x;
    cin >> t;
    while (t > 0) {
        t--;
        cin >> x;
        cout << c[x] << "\n";
    }

    return 0;
}
