#include <bits/stdc++.h>

using namespace std;

struct sa {
    int s, st, fi;
    sa(int sum, int start, int finish) {
        s = sum;
        st = start;
        fi = finish;
    }
};
bool comp(sa sa1, sa sa2) {
    if (sa1.s == sa2.s) {
        if (sa1.fi == sa2.fi)
            return sa1.st > sa2.st;
        return sa1.fi < sa2.fi;
    }
    return sa1.s < sa2.s;
}
int numberOfSubArray(vector<int> arr)
{
    int su[52]; su[0] = arr[0];
    for (int i = 1; i < arr.size(); i++)
        su[i] = su[i - 1] + arr[i];
    vector<sa> sums;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < (arr.size() - i); j++) {
            sums.push_back(sa(su[j + i] - su[j - 1], j, j + i));
        }
    }
    sort(sums.begin(), sums.end(), comp);
    sums.push_back(sa(sums.back().s + 1, sums.back().st, sums.back().fi));
    int maxs = 1, curc = 1;
    sa cur = sums[0];
    for (int i = 1; i < sums.size(); i++) {
        //cout << sums[i].s << " " << sums[i].st << "-" << sums[i].fi << endl;
        if (sums[i].s == sums[i - 1].s) {
            if (sums[i].st > cur.fi) {
                cur = sums[i];
                curc++;
            }
        } else {
            maxs = max(maxs, curc);
            curc = 1;
            cur = sums[i];
        }
    }
    //if ((sums[sums.size() - 1].s == sums[sums.size() - 2].s) &&
    //    (sums[sums.size() - 1].st > sums[sums.size() - 2].fi))
    //    maxs = max(maxs, curc);
    return maxs;
}

int main()
{
    /*cout << (numberOfSubArray({-7,-8,-15,13,-5,-7,-4,-5,-8,29,-3
                             ,-2,7,-12,3,-2,-9,4,24,1,-11,14,-2,-13,-15,-3,18,-1,4}) == 6);*/
    //cout << (numberOfSubArray({1,1,1,1}) == 4);
    cout << (numberOfSubArray({-1,-2,-1,2,-3,9,-8}) == 3);
    return 0;
}
