#include <bits/stdc++.h>

using namespace std;

int x, i, j;

int main()
{
    cin >> x;
    i = 1; j = 1;
    while (x == 0) {
        cin >> x;
        if (i < 5)
            i++;
        else {
            i = 1;
            j++;
        }
    }

    cout << abs(i - 3) + abs(j - 3);
    //system("PAUSE");

    return 0;
}
