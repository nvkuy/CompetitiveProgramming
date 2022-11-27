/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll rec(ll h, vector<int> &a, int i, int green, int blue) {
    if (i>=a.size()) return 0;
    
    if (h>a[i]) {
        return 1+ rec(h+a[i]/2, a, i+1, green, blue);
    }
    
    ll result = rec(h, a, i+1, green, blue);
    
    if (green>0 && h*2>a[i]) result = max(result, 1+rec(h*2+a[i]/2, a, i+1, green-1, blue));
    if (blue>0 && h*3>a[i]) result = max(result, 1+rec(h*3+a[i]/2, a, i+1, green, blue-1));
    if (green>1 && h*2*2>a[i]) result = max(result, 1+rec(h*2*2+a[i]/2, a, i+1, green-2, blue));
    if (blue>0 && green>0 && h*2*3>a[i]) result = max(result, 1+rec(h*2*3+a[i]/2, a, i+1, green-1, blue-1));
    if (blue>0 && green>1 && h*2*2*3>a[i]) result = max(result, 1+rec(h*2*2*3+a[i]/2, a, i+1, green-2, blue-1));
    
    return result;
}

int main()
{
  
    int t;
    cin>>t; 
    
    while(t--) {
        ll n, h;
        cin >>n>>h;
        
        vector<int> a(n);
        for (int i=0; i<n; ++i) {
            cin>>a[i];
        }
        
        sort(a.begin(), a.end());
        
        // int res=0, green=2, blue=1;
        // for (int i=0; i<n; ++i) {
            
        //     if (h>a[i]) {res++; h+=a[i]/2;}
        //     else {
        //         res++;
        //         if (green>0 && h*2>a[i]) {h*=2; green--; h+=a[i]/2;}
        //         else if (blue>0 && h*3>a[i]) {h*=3; blue--;}
        //         else if (green>1 && h*2*2>a[i]) {h*=4; green-=2; h+=a[i]/2;}
        //         else if (blue>0 && green>0 && h*2*3>a[i]) {h*=6; blue--;green--; h+=a[i]/2;}
        //         else if (blue>0 && green>1 && h*2*2*3>a[i]) {h*=12; blue--; green-=2; h+=a[i]/2;}
        //         else res--;
        //     }
        // }
        ll res = rec(h, a, 0, 2, 1);
        
        cout << res << "\n";
    }
     return 0;
}