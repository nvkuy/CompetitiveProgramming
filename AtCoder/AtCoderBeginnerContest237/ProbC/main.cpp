#include <bits/stdc++.h>

using namespace std;

bool check(string s) {
    reverse(s.begin(), s.end());
    int c = 0, j = s.length() - 1;
    while (s[j] == 'a') {
        j--;
        c--;
        if (j < 0)
            break;
    }
    j = 0;
    while (s[j] == 'a') {
        j++;
        c++;
        if (j >= s.length())
            break;
    }
    if (c < 0)
        return false;
    while (c--)
        s.push_back('a');
    j = s.length();
    for (int i = 0; i < j / 2; i++)
        if (s[i] != s[j - i - 1])
            return false;
    return true;
}

int main()
{
    string s;
    getline(cin, s);
    if (check(s))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
