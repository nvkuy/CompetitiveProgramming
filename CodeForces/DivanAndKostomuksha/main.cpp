#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{

    int n, ans, t;
    scanf("%d", &n);
    scanf("%d", &ans);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        ans = gcd(ans, t);
        if (ans == 1)
            break;
    }
    printf("%d", ans);

    return 0;
}
