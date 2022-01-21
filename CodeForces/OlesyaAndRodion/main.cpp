#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, t;
    string s;
    cin >> n >> t;
    s = to_string(t);
    if (n < s.length())
        cout << -1;
    else {
        cout << s;
        for (int i = 0; i < n - s.length(); i++)
            cout << "0";
    }

    return 0;
}
