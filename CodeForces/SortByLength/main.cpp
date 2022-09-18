#include <bits/stdc++.h>

using namespace std;

struct str {
    string st;
    int tt;
    str(string s, int i) {
        st = s;
        tt = i;
    }
};
bool compare(str str1, str str2) {
    if (str1.st.length() == str2.st.length()) {
        return str1.tt < str1.tt;
    } else
        return str1.st.length() < str2.st.length();
}
vector<string> sortByLength(vector<string> arr)
{
    vector <str> strs;
    for (int i = 0; i < arr.size(); i++) {
        //strs[i].st = arr[i];
        //strs[i].tt = i;
        strs.push_back(str(arr[i], i));
    }
    sort(strs.begin(), strs.end(), compare);
    //for (int i = 0; i < strs.size(); i++)
    //    cout << strs[i].st << " ";
    //cout << endl;
    vector <string> ans;
    for (int i = 0; i < arr.size(); i++)
        ans.push_back(strs[i].st);
    return ans;
}

int main()
{
    vector <string> test = {"abc", "", "aaa", "a", "zz"};
    test = sortByLength(test);
    for (int i = 0; i < test.size(); i++)
        cout << test[i] << " ";
    cout << endl;
    return 0;
}
