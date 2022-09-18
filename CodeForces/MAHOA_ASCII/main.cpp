#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s, ans;
    getline(cin, s);
    int i = 0, n;
    //bool iec = true;
    while (i < s.length()) {
        n = 0;
        n += ((s[i] - '0') * 10);
        //if (i == s.length() - 1) {
        //    iec = false;
        //    break;
        //}
        i++;
        n += (s[i] - '0');
        if (n < 65) {
            i++;
            n *= 10;
            n += (s[i] - '0');
        }
        ans.push_back((char)(n));
        i++;
    }
    cout << ans << endl;

    return 0;
}
