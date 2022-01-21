#include <bits/stdc++.h>

using namespace std;

int n, c, a, b, d;

int main()
{

    cin >> n;

    c = 0;
    while (n > 0) {
        n--;
        cin >> a >> b >> d;
        if (a + b + d >= 2)
            c++;
    }
    cout << c;

    return 0;
}
