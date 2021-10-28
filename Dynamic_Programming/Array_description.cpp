#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
using namespace std;
ll solve(vector<int> &a,int m)
{
    int n=a.size();
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
 
    ll ans=0;
    for(int i=0;i<n;i++){
        for(int x=1;x<=m;x++){
            if(i==0)
            {   if(a[i]==x||a[i]==0)
                dp[i][x]=1;
                else
                dp[i][x]=0;
 
            }
            else
            {
                 if(a[i]==x||a[i]==0)
                  dp[i][x]=((dp[i-1][x-1]+dp[i-1][x+1])%mod+dp[i-1][x])%mod;
                  else
                  dp[i][x]=0;
            }
        }
    }
    for(int x=1;x<=m;x++) ans=(ans+dp[n-1][x])%mod;
    return ans;
    
}
int main()
{
   ll n,m;
   cin>>n>>m;
   vector<int> a(n);
   for(int i=0;i<n;i++) cin>>a[i];
   ll res= solve(a,m);
   cout<<res<<endl;
}
