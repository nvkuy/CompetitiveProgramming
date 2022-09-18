#include <bits/stdc++.h>

using namespace std;

int f[1000002];
bool nts[1000002];

void snt(int n) {
    for (int i = 0; i <= n; i++)
        nts[i] = true;
    nts[0] = false; nts[1] = false;
    for(int i = 2; i * i <= n; ++i) {
         if(nts[i] == true) {
             for(int j = i * i; j <= n; j += i)
                 nts[j] = false;
        }
    }
}

int main()
{
    snt(1000002);
    f[0] = 0; f[1] = 0;
    for (int i = 2; i <= 1000002; i++) {
        if (nts[i])
            f[i] = f[i - 1] + 1;
        else
            f[i] = f[i - 1];
    }
    int t, l, r;
    cin >> t;
    while (t > 0) {
        t--;
        cin >> l >> r;
        cout << (f[max(l, r)] - f[min(l, r) - 1]) << "\n";
    }
    return 0;
}
