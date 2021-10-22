#include<bits/stdc++.h>
using namespace std;
int main() 
{
    long long n,temp;
    int cnt=0;
    cin>>n;
    while(n)
    {
        temp=n;
        long long  mx=-1;
        while(temp) {mx=max(mx,temp%10),temp/=10;}
        n-=mx;
        cnt+=1;
    }
    cout<<cnt<<endl;
 
}
