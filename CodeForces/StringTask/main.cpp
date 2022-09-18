#include <bits/stdc++.h>

using namespace std;

bool lt[400] = {false};
vector<char> arrC;
string s;
char t;

int main()
{

    cin >> s;

    lt['a'] = 1; lt['o'] = 1; lt['y'] = 1; lt['e'] = 1; lt['u'] = 1; lt['i'] = 1;
    for (int i = 0; i < s.length(); i++) {
        t = tolower(s[i]);
        if (lt[t])
            continue;
        arrC.push_back('.');
        arrC.push_back(t);
    }

    for (int i = 0; i < arrC.size(); i++)
        cout << arrC.at(i);

    return 0;
}
