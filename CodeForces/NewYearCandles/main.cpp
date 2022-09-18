#include <bits/stdc++.h>

using namespace std;

int a, b, t, nm, ns;

int main()
{

    cin >> a >> b;

    t = 0; nm = 0; ns = 0;
    while (a > 0) {
        nm = (int)(a / b);
        ns = ((int)(a / b)) * b;
        t += ns;
        a = a - ns + nm;
        if (a < b) {
            t += a;
            a = 0;
        }
    }

    cout << t;

    return 0;
}
