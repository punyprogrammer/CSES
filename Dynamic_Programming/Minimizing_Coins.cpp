#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    ll x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= x; i++)
        for (int c = 0; c < n; c++)
        {
            if (i - a[c] >= 0 && dp[i - a[c]] != INT_MAX)
                dp[i] = min(dp[i - a[c]] + 1, dp[i]);
        }
    if (dp[x] == INT_MAX)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << dp[x] << endl;
}
