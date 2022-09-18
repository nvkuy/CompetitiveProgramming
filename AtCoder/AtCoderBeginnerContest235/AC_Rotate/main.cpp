#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c;
    string s;
    getline(cin, s);
    a = s[0] - '0';
    b = s[1] - '0';
    c = s[2] - '0';
    cout << a * 100 + b * 10 + c + 100 * b + 10 * c + a + 100 * c + 10 * a + b;

    return 0;
}
