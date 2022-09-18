#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int p = s.find("((");
    if ((p == -1) || (p + 2 == s.length())) {
        p = s.find("(");
        s.erase(s.begin() + p);
    } else
        s.erase(s.begin() + p);
    //cout << p << endl;
    //cout << s.find(")", p) << endl;
    s.erase(s.begin() + s.find(")", p));
    cout << s;

    return 0;
}
