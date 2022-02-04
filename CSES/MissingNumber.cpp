#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, ai, s;
    cin >> n;
    s = ((n + 1) * n) / 2;
    while ((n--) > 1) {
        cin >> ai;
        s -= ai;
    }
    cout << s;
    
    return 0;
}
