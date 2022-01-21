#include <bits/stdc++.h>

using namespace std;
/*
bool compare(vector<int> p1, vector<int> p2) {
    if (p1[0] < p2[0])
        return true;
    else if (p1[0] == p2[0]) {
        if (p1[1] < p2[1])
            return true;
        else
            return false;
    } else
        return false;
}
*/
int tvh(vector<int> vt1, vector<int> vt2) {
    return ((vt1[0] * vt2[0]) + (vt1[1] * vt2[1]));
}
bool isRectangle(std::vector<std::vector<int>> ps)
{
    //sort(ps.begin(), ps.end(), compare);
    //for (int i = 0; i < ps.size(); i++)
    //    cout << ps[i][0] << ", " << ps[i][1] << "   ";
    //cout << endl;
    vector <int> vt1 = {ps[0][0] - ps[1][0], ps[0][1] - ps[1][1]};
    vector <int> vt2 = {ps[1][0] - ps[2][0], ps[1][1] - ps[2][1]};
    vector <int> vt3 = {ps[2][0] - ps[3][0], ps[2][1] - ps[3][1]};
    vector <int> vt4 = {ps[3][0] - ps[0][0], ps[3][1] - ps[0][1]};
    //cout << vt1[0] << " " << vt1[1] << endl;
    //cout << vt2[0] << " " << vt2[1] << endl;
    //cout << tvh(vt1, vt2) << endl;
    if (tvh(vt1, vt2) != 0)
        return false;
    if (tvh(vt2, vt3) != 0)
        return false;
    if (tvh(vt3, vt4) != 0)
        return false;
    return true;
}

int main()
{
    cout << isRectangle({{0,0},   {1,1},   {0,2},   {-1,1}}) << endl;
    return 0;
}
