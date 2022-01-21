#include <bits/stdc++.h>

using namespace std;

bool nt[10000001];
long t, a, b;
float c, tmp;

void snt(int b) {

    fill_n(nt, b, true);

    nt[1] = false;

    for (int i = 2; i * i <= b; i++) {
        if (nt[i]) {
            for (int j = i * i; j <= b; j += i)
                nt[j] = false;
        }
    }

}

int main()
{

    //cout << fixed;
    //cout << setprecision(2);
    snt(10000001);

    cin >> t;
    while (t > 0) {
        t--;
        cin >> a >> b;
        //snt(b);
        tmp = 0;
        c = 0;
        for (int i = a; i <= b; i++) {
            if (nt[i] == true) {
                tmp += i;
                c++;
                //cout << i << " ";
            }
        }
        //cout << endl;

        printf("%.2f \n", ((float)(tmp / c)));

    }

    return 0;
}
