#include <bits/stdc++.h>

using namespace std;

int n, x;
char a, b, c;

int main()
{

    cin >> n;
    x = 0;
    while (n > 0) {
        n--;
        cin >> a >> b >> c;
        if ((a == '+') || (b == '+'))
            x++;
        else
            x--;
    }

    cout << x;

    return 0;
}
