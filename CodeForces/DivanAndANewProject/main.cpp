#include <bits/stdc++.h>

using namespace std;

struct bd {
    long long pp;
    long long vt;
    bd(int plpos, int visti) {
        pp = plpos;
        vt = visti;
    }
};

struct bda {
    long long cor;
    long long plp;
    bda(int plpos, int cord) {
        plp = plpos;
        cor = cord;
    }
};

bool cmp(bd b1, bd b2) {
    return (b1.vt > b2.vt);
}

bool cmpa(bda b1, bda b2) {
    return (b1.plp < b2.plp);
}

vector<bd> bds;
deque<bda> dqbd;

int main()
{

    long long ans;
    int t, n, tmp, cl, cr;
    scanf("%d", &t);
    while (t--) {
        bds.clear();
        dqbd.clear();
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &tmp);
            bds.push_back(bd(i, tmp));
        }
        sort(bds.begin(), bds.end(), cmp);
        ans = 0, cl = 1, cr = 1;
        for (int i = 0; i < bds.size(); i++) {
            if (cl > cr) {
                dqbd.push_back(bda(bds[i].pp, cr));
                ans += (long long)(bds[i].vt * cr * 2);
                cr++;
            } else {
                dqbd.push_front(bda(bds[i].pp, -cl));
                ans += (long long)(bds[i].vt * cl * 2);
                cl++;
            }
        }
        sort(dqbd.begin(), dqbd.end(), cmpa);
        printf("%lld\n", ans);
        printf("0");
        for (int i = 0; i < dqbd.size(); i++)
            printf(" %d", dqbd[i].cor);
        printf("\n");
    }

    return 0;
}
