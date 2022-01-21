#include <bits/stdc++.h>

using namespace std;

long n, b, c;
int a[5] = {1, 5, 10, 20, 100};

int main()
{

    cin >> n;

    b = 0;
    c = 4;
    while (n > 0) {
        b += (n / a[c]);
        n = n % a[c];
        c--;
    }

    cout << b;

    return 0;
}
