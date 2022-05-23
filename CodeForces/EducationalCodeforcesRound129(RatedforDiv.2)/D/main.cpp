#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

string add(string a, string b)
{
    string res="";
    while(a.length() < b.length()) a="0"+a;
    while(b.length() < a.length()) b="0"+b;
    int carry=0;
    for(int i=a.length()-1;i>=0;i--)
    {
        int tmp=a[i]-48 + b[i]-48 + carry;
        carry=tmp/10;
        tmp=tmp%10;
        res=(char)(tmp+48)+res;
    }
    if(carry>0) res="1"+res;
    return res;
}

string sub(string a, string b)
{
    string res="";
    while(a.length() < b.length()) a="0"+a;
    while(b.length() < a.length()) b="0"+b;
    bool neg=false;
    if(a<b)
    {
        swap(a,b);
        neg=true;
    }
    int borrow=0;
    for(int i=a.length()-1; i>=0;i--)
    {
        int tmp=a[i]-b[i]-borrow;
        if(tmp<0)
        {
            tmp+=10;
            borrow=1;
        }
        else borrow=0;
        res=(char)(tmp%10 + 48) + res;
    }
    while(res.length()>1 && res[0]=='0') res.erase(0,1);
    if(neg) res="-"+res;
    return res;
}

string mul(string a, string b)
{
    string res="";
    int n=a.length();
    int m=b.length();
    int len=n+m-1;
    int carry=0;
    for(int i=len;i>=0;i--)
    {
        int tmp=0;
        for(int j=n-1;j>=0;j--)
            if(i-j<=m && i-j>=1)
            {
                int a1=a[j]-48;
                int b1=b[i-j-1]-48;
                tmp+=a1*b1;
            }
            tmp+=carry;
            carry=tmp/10;
            res=(char)(tmp%10 + 48)+res;
    }
    while(res.length()>1 && res[0]=='0') res.erase(0,1);
    return res;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, x, ans = 1e9;
    cin >> n >> x;
    string s = to_string(x);
    set<string> dd;
    queue<pair<string, int>> q;
    q.push({s, 0});
    while (!q.empty()) {
        pair<string, int> tmp = q.front();
        q.pop();
        if (tmp.first.length() == n) {
            ans = tmp.second;
            break;
        }
        string u = tmp.first;
        for (int i = 0; i < u.length(); i++) {
            string tt; tt.push_back(u[i]);
            string v = mul(u, tt);
            if (dd.find(v) == dd.end()) {
                q.push({v, tmp.second + 1});
                dd.insert(v);
            }
        }
    }
    if (ans == 1e9)
        ans = -1;
    cout << ans;

    return 0;
}
