#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION";
        return 0;
    }
    for (int i = n - (1 - (n % 2)); i >= 1; i-=2)
        cout << i << ' ';
    for (int i = n - (n % 2); i >= 1; i-=2)
        cout << i << ' ';

    return 0;
}
