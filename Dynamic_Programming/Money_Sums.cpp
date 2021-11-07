#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main()
{
     int n;
     cin>>n;
     vector<int> a(n);
     int sum=0;
     for(int i=0;i<n;i++) cin>>a[i],sum+=a[i];
     int k=0;
     vector<bool> dp(sum+1,false);
     dp[0]=true;
     for(int i=0;i<n;i++) 
     {
         for(int j=sum;j>=a[i];j--)
             {
                 dp[j]= dp[j]||dp[j-a[i]];
             }
     }
     vector<int> ans;
     for(int i=1;i<=sum;i++)
         if(dp[i]) ans.push_back(i),k++;
        cout<<k<<endl;
        for(auto i: ans) cout<<i<<" ";
 
}
