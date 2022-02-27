#include <bits/stdc++.h>

using namespace std;

int main()
{

    int ans = 0, a[10];
    for (int i = 0; i <= 9; i++)
        cin >> a[i];
    for (int i = 0; i < 3; i++)
        ans = a[ans];
    cout << ans;

    return 0;
}
