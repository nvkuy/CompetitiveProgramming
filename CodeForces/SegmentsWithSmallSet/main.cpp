#include <bits/stdc++.h>

using namespace std;

int main()
{

    long long n, k, a[100001];
    int b[100001];
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    memset(b, 0, sizeof(b));
    long long j = 0, c = 0;
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
        //cout << ans << endl;
        if (b[a[i]] == 0)
            c++;
        b[a[i]]++;
        while (c > k) {
            if (b[a[j]] <= 1)
                c--;
            b[a[j]]--;
            j++;
        }
        ans += (i - j + 1);
    }
    cout << ans;

    return 0;
}
