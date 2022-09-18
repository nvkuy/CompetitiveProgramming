#include <bits/stdc++.h>

using namespace std;

int main()
{
    int te, c[202];
    string s, t, tmp;
    cin >> te;
    cin.ignore();
    while (te--) {
        getline(cin, s);
        getline(cin, t);
        memset(c, 0, sizeof(c));
        for (int i = 0; i < s.length(); i++)
            c[(int)(s[i])]++;
        if (c[(int)t[0]] > 0 && c[(int)t[1]] > 0 && c[(int)t[2]] > 0) {
            tmp = t;
            sort(t.begin(), t.end());
            if (t == tmp) {
                t[2] = tmp[1];
                t[1] = tmp[2];
            }
            while (c[(int)t[0]]--)
                cout << t[0];
            while (c[(int)t[1]]--)
                cout << t[1];
            while (c[(int)t[2]]--)
                cout << t[2];
        }
        for (int i = 0; i <= 200; i++) {
            if (c[i] <= 0)
                continue;
            while (c[i]--)
                cout << (char)i;
        }
        cout << endl;
        /*
        int j = 0, k = -1;
        for (int i = 0; i <= 200; i++) {
            if (c[i] <= 0)
                continue;
            if (j > 2) {
                while (c[i]--)
                    cout << (char)(i);
                continue;
            }
            if ((char)(i) == t[j]) {
                if (j < 1) {
                    while (c[i]--)
                        cout << (char)(i);
                } else {
                    if (k < 0)
                        k = i;
                    else {
                        while (c[i]--)
                            cout << (char)(i);
                        while (c[k]--)
                            cout << (char)(k);
                        k = -1;
                    }
                }
                j++;
            } else {
                while (c[i]--)
                    cout << (char)(i);
            }
        }
        if (k >= 0)
            while (c[k]--)
                cout << (char)(k);
        cout << endl;
        //cout << j << '|' << k << endl;
        */
    }

    return 0;
}
