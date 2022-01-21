#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long k;
    cin >> k;
    bitset<64> bs(k);
    string s = bs.to_string();
    int i = 0;
    while (s[i] == '0')
        i++;
    while (i < 64) {
        cout << ((s[i] == '1') ? '2' : '0');
        i++;
    }

    return 0;
}
