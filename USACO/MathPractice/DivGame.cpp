#include <bits/stdc++.h>
using namespace std;

int main() {

    long long n, ans = 0;
    cin >> n;

    for (long long i = 2; i * i <= n; i++) {
        int cnt = 0, tmp = 1;
        while (n % i == 0) {
            cnt++;
            n /= i;
        }
        while (true) {
            if (cnt < tmp) break;
            ans++;
            cnt -= tmp;
            tmp++;
        }
    }
    if (n > 1) ans++;

    cout << ans << endl;

    return 0;
}