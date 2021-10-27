#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int main(){
    int n;
    cin>>n;
    char grid[n][n];
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>grid[i][j];
    if(grid[0][0]=='*'||grid[n-1][n-1]=='*')
         {
             cout<<0<<endl;
             return 0;
         }
    dp[0][0]=1;
    for(int i=1;i<n;i++) 
    {
        if(grid[0][i]=='*') 
            break;
        dp[0][i]=1;
    }
    for(int i=1;i<n;i++) 
    {
        if(grid[i][0]=='*') 
            break;
        dp[i][0]=1;
    }
    for(int i=1;i<n;i++)
        for(int j=1;j<n;j++){
            if(grid[i][j]=='.')
               dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
        }
    cout<<dp[n-1][n-1]<<endl;
}
