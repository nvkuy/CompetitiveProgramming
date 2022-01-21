#include <bits/stdc++.h>

using namespace std;

bool nt[35000000];
long long s[2500001];

int main()
{
    memset(nt, true, sizeof(nt));
    memset(s, 0, sizeof(s));
    nt[1] = false;

    for(int i = 2; i * i <= 35000000; ++i) {
        if(nt[i] == true) {
            for(int j = i * i; j <= 35000000; j += i)
                nt[j] = false;
        }
    }
    int j = 0;
    for (int i = 2; i <= 35000000; i++) {
        if (nt[i]) {
            j++;
            s[j] = s[j - 1] + i;
        }
    }

    int t, n;
    cin >> t;
    while (t > 0) {
        t--;
        cin >> n;
        cout << s[n] << "\n";
    }

    return 0;
}
