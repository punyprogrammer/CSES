#include<bits/stdc++.h>
#define maxN 1000001
using namespace std;
vector<int> a[maxN];
bool vi[maxN];
void dfs(int s)
{
    vi[s]=true;
    for(int ch:a[s]) if(!vi[ch]) dfs(ch);
}
int main()
{
    vector<int> ans;
    int n,m,x,y,k=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++) a[i].clear(),vi[i]=false;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vi[i])
        {
            ans.push_back(i);
            k++;
            dfs(i);
        }
    }
    cout<<k-1<<endl;
    for(int i=1;i<ans.size();i++)
    cout<<ans[i-1]<<" "<<ans[i]<<endl;
 
}
