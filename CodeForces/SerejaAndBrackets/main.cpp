#include <bits/stdc++.h>

using namespace std;

int main()
{

    scanf("%s", &s);
    ob[0] = 0, cb[0] = 0;
    for (int i = 0; i < s.length(); i++) {
        ob[i + 1] = ob[i];
        if (s[i] == '(')
            ob[i + 1]++;
    }
    for (int i = (s.length() - 1); i >= 0; i--) {
        cb[i] = cb[i + 1];
        if (s[i] == ')')
            cb[i]++;
    }
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &l, &r);
        //printf("%d\n", );
    }

    return 0;
}
