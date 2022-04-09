#include <bits/stdc++.h>
using namespace std;

int dp[14][2][2][150][150];

int f(int ind,int st,int sm,int val,int sod){
    if(sod<0)return 0;
    if(ind==n)return val==1&&sod==0;
    int &ans = dp[ind][st][sm][val][sod];
    if(ans!=-1)return ans;
    ans= 0;
    if(sm){
        rep(d,10){
            int nst = 1;
            int nval = val / __gcd(d,val);
            if(d==0)if(!st)nst=0,nval=val;
            // wrt(ind,st,sm,val,sod);
            ans += f(ind+1,nst,1,nval,sod-d);
        }
    }else{
        int d = s[ind] - '0';
        rep(x,d){
            int nst = 1;
            int nval = val / __gcd(x,val);
            if(x==0)if(!st)nst=0,nval= val;
            ans += f(ind+1,nst,1,nval,sod-x);
        }
        int nval = val / __gcd(d,val);
        ans += f(ind+1,1,0,nval,sod-d);
    }
   
    return ans;
}


