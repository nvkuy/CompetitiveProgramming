#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

bool dd[1000001];

int main()
{
    int n, ai, cgcd, co;
    cin >> n;
    memset(dd, false, sizeof(dd));
    for (int i = 0; i < n; i++) {
        cin >> ai;
        dd[ai] = true;
    }
    co = 0;
    for (int i = 1; i <= 1e6; i++) {
        if (dd[i])
            continue;
        cgcd = 0;
        for (int j = i; j <= 1e6; j += i) {
            if (!dd[j])
                continue;
            if (cgcd == 0)
                cgcd = j;
            else
                cgcd = gcd(cgcd, j);
            if (cgcd == i)
                break;
        }
        co += (cgcd == i);
    }
    cout << co;

    return 0;
}
