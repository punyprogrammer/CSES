#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main()
{
    int n;
    ll  s,e,r;
    vector<vector<ll>> dat;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s>>e>>r;
        dat.push_back({e,s,r});}
    //sort by ending time ;
    sort(dat.begin(),dat.end());
    vector<ll> end;
    
    for(int i=0;i<n;i++) end.push_back(dat[i][0]);
 
    ll dp[n];
    dp[0]=dat[0][2];
    for(int i=1;i<n;i++)
    {
        ll temp=dat[i][2];
        int  ce=lower_bound(end.begin(),end.end(),dat[i][1])-end.begin();
        ce-=1;
        if(ce!=-1) temp+=dp[ce];
        
        dp[i]=max(dp[i-1],temp);
    }
    cout<<dp[n-1]<<endl;
 
}
