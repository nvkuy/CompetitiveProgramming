#include <bits/stdc++.h>

using namespace std;

bool nt[2000000];
int f[2000000];

int main()
{
    memset(nt, true, sizeof(nt));
    memset(f, 0, sizeof(f));
    nt[1] = false;

    for(int i = 2; i * i <= 2000000; ++i) {
        if(nt[i] == true) {
            for(int j = i * i; j <= 2000000; j += i)
                nt[j] = false;
        }
    }
    int j = 2000000;
    while (!nt[j])
        j--;
    f[j] = j;
    for (int i = j; i >= 0; i--) {
        if ((nt[i]) && (i % 11 == 1))
            j = i;
        f[i] = j;
        //printf("%d\n", f[i]);
    }

    int t, n;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        scanf("%d", &n);
        printf("%d\n", f[n]);
    }

    return 0;
}
