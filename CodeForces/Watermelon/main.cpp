#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{

    cin >> n;

    if (n % 2 == 0) {
        if (n > 2)
            cout << "YES";
        else
            cout << "NO";
    } else
        cout << "NO";

    return 0;
}
