#include <bits/stdc++.h>
using namespace std;
int n, m;
int ans = 0;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int vis[1001][1001];
char grid[1001][1001];
bool isValid(int y, int x)
{
  if (y < 0)
    return false;
  if (x < 0)
    return false;
  if (y >= n)
    return false;
  if (x >= m)
    return false;
  if (grid[y][x] == '#')
    return false;

  return true;
}
void dfs(int y, int x)
{

  vis[y][x] = 1;
  for (int i = 0; i < 4; i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (isValid(ny, nx))
    {
      if (!vis[ny][nx])
      {
        dfs(ny, nx);
      }
    }
  }
}

int main()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];
      vis[i][j] = 0;
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (grid[i][j] == '.' and !vis[i][j])
      {
        dfs(i, j);
        ans++;
      }
    }
  }

  cout << ans << endl;
  return 0;
}