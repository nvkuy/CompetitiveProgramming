#include <bits/stdc++.h>

using namespace std;

bool check(string n) {
    int s = 0;
    for (int i = 0; i < n.length(); i++)
        s += (n[i] - '0');
    return (s % 4 == 0);
}

int main()
{
    int n;
    cin >> n;
    while (!check(to_string(n)))
        n++;
    cout << n << endl;

    return 0;
}
