#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
using namespace std;
int main()
{   
    ll n;
    cin>>n;
    ll dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=6;j++)
    {
        if(i>=j) dp[i]=(dp[i]+dp[i-j])%mod;
    }
    cout<<dp[n]<<endl;
    
    
}
