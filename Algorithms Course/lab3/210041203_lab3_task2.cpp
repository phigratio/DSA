#include <bits/stdc++.h>
using namespace std;
int n, m;
int ans = 0;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int visited[1001][1001];
char matrix[1001][1001];
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
  if (matrix[y][x] == '#')
    return false;

  return true;
}
void dfs(int y, int x)
{

  visited[y][x] = 1;
  for (int i = 0; i < 4; i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (isValid(ny, nx))
    {
      if (!visited[ny][nx])
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
      cin >> matrix[i][j];
      visited[i][j] = 0;
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (matrix[i][j] == '.' and !visited[i][j])
      {
        dfs(i, j);
        ans++;
      }
    }
  }

  cout << ans << endl;
  return 0;
}