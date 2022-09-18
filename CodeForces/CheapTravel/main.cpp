#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if ((m * a) < b)
        cout << n * a;
    else {
        if (((n % m) * a) < b)
            cout << ((n / m) * b) + ((n % m) * a);
        else
            cout << ceil((float)(n) / (float)(m)) * b;
    }

    return 0;
}
