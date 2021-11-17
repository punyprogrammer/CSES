#include <bits/stdc++.h>
using namespace std;
char grid[1001][1001];
bool vi[1001][1001];
int cnt = 0;
void dfs(int x, int y, int n, int m)
{
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '#' || vi[x][y])
        return;
    vi[x][y] = true;
    dfs(x + 1, y, n, m);
    dfs(x, y + 1, n, m);
    dfs(x - 1, y, n, m);
    dfs(x, y - 1, n, m);
}
int main()
{
    int n, m;
    cin >> n >> m;
    memset(vi, 0, sizeof vi);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (!vi[i][j] && grid[i][j] == '.')
                dfs(i, j, n, m), cnt++;
        }
    cout << cnt << endl;
}
