#include<bits/stdc++.h>
#define maxN 1000001
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> a[n+1];
    vector<bool> vi(n+1);
    vector<int> pa(n+1,-1);
    int x,y;
    for(int i=1;i<=n;i++) a[i].clear(),vi[i]=false;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int dp[n+1];
    dp[1]=0;
    queue<int> q;
    q.push(1);
    vi[1]=true;
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        for(int ch: a[p])
        {
            if(!vi[ch])
            {
                vi[ch]=true;
                dp[ch]=dp[p]+1;
                pa[ch]=p;
                q.push(ch);
            }
        }
    }
    if(!vi[n])
        cout<<"IMPOSSIBLE"<<endl;
    else
        {
            vector<int> ans;
            int x;
            x=n;
            while(pa[x]!=-1)
            {
                ans.push_back(x);
                x=pa[x];
            }
            ans.push_back(1);
            reverse(ans.begin(),ans.end());
            cout<<dp[n]+1<<endl;
            for(int i:ans)
                cout<<i<<" ";
 
        }
}
