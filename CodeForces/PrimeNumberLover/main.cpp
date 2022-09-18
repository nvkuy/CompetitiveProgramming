#include <bits/stdc++.h>

using namespace std;

int main()
{

    bool snt[1000001];
    memset(snt, true, sizeof(snt));
    snt[0] = false;
    snt[1] = false;
    for(int i = 2; i * i <= 1000001; ++i) {
         if(snt[i] == true) {
             for(int j = i * i; j <= 1000001; j += i)
                 snt[j] = false;
        }
    }
    int n, a[100001];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long ans = snt[a[0]];
    int d = snt[a[0]];
    for (int i = 1; i < n; i++) {
        if (snt[a[i]]) {
            d++;
            if (d > i) {
                ans += (i + 1);
                continue;
            }
            ans += (d + 1);
        } else {
            d--;
            if (d < 0) {
                d = 0;
                continue;
            }
            ans += (d + 1);
        }
    }
    cout << ans;

    return 0;
}
