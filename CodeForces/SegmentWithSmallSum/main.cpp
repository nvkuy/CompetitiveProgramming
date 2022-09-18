#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    long long s, a[100001];
    //long long s, b[100001];
    cin >> n >> s;
    //b[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        //b[i] = b[i - 1] + a[i];
    }
    long long cs = 0;
    int j = 1, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > s) {
            j = i + 1;
            cs = 0;
            continue;
        }
        cs += a[i];
        while (cs > s) {
            cs -= a[j];
            j++;
        }
        ans = max(ans, i - j + 1);
    }
    cout << ans;
    /*
    for (int j = n - 1; j >= 0; j--) {
        for (int i = 1; i + j <= n; i++) {
            if (b[i + j] - b[i - 1] <= s) {
                printf("%d", j + 1);
                return 0;
            }
        }
    }
    printf("0");
    */

    return 0;
}
