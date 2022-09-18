#include <bits/stdc++.h>

using namespace std;

int main()
{

    long long int n;
    cin >> n;
    if (n >= -(1LL << 31LL) && n <= (1LL << 31LL) - 1LL)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
