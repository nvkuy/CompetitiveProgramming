#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t, n, tmp, en, on, x;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        on = 0, en = 0;
        while (n--) {
            cin >> tmp;
            if (tmp % 2)
                on++;
            else
                en++;
        }
        //printf("odd: %d, even: %d\n", on, en);
        if (x % 2) {
            if (on < 1) {
                printf("No\n");
                continue;
            }
            if (x <= (on + ((en / 2) * 2) - (1 - (on % 2)))) {
                printf("Yes\n");
                continue;
            }
            printf("No\n");
        } else {
            if (en < 1 || on < 1) {
                printf("No\n");
                continue;
            }
            if (x <= (on + en - (1 - (on % 2)) - (1 - (en % 2)))) {
                printf("Yes\n");
                continue;
            }
            printf("No\n");
        }
    }

    return 0;
}
