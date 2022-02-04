#include <bits/stdc++.h>

using namespace std;

int main()
{
    
    string s;
    int cc = 1, mc = 1;
    getline(cin, s);
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1])
            cc++;
        else
            cc = 1;
        mc = max(mc, cc);
    }
    cout << mc;
    
    return 0;
}
