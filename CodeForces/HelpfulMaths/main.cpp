#include <bits/stdc++.h>

using namespace std;

string s;
int a, b, c;

int main()
{

    cin >> s;

    if (s.length() == 1)
        cout << s;
    else {

        a = 0, b = 0, c = 0;
        for (int i = 0; i < s.length(); i+=2) {
            if (s[i] == '1')
                a++;
            else if (s[i] == '2')
                b++;
            else
                c++;
        }
        //1
        while (a > 1) {
            cout << "1+";
            a--;
        }
        if (a >= 1) {
        if ((b > 0) || (c > 0))
            cout << "1+";
        else
            cout << "1";
        }
        //2
        while (b > 1) {
            cout << "2+";
            b--;
        }
        if (b >= 1) {
        if (c > 0)
            cout << "2+";
        else
            cout << "2";
        }
        //3
        while (c > 1) {
            cout << "3+";
            c--;
        }
        if (c >= 1)
            cout << "3";

    }

    return 0;
}
