#include <bits/stdc++.h>

using namespace std;

int n;
bool nt[1000001];

int main()
{

    cin >> n;
    nt[1] = false;
    for (int i = 2; i <= n; i++)
        nt[i] = true;
    for (int i = 2; i * i <= n; i++) {
        if (nt[i]) {
            for (int j = 2; i * j <= n; j++)
                nt[i * j] = false;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += nt[i];
    cout << ans;

    return 0;
}
