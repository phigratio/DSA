#include <bits/stdc++.h>
using namespace std;

const int maxi = 1e5 + 1;
int n, m;
int si, sj, ti, tj;
char dc[4] = {'U', 'D', 'L', 'R'};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int visited[1001][1001];
string matrix[1001];
string par[1001];
string step = "";

bool isValid(int x, int y)
{
  return x >= 0 && y >= 0 && x < n && y < m && matrix[x][y] == '.';
}

void dfs(int y, int x)
{
  visited[y][x] = 1;
  for (int i = 0; i < 4; i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (isValid(nx, ny) && !visited[ny][nx])
    {
      dfs(ny, nx);
    }
  }
}

int main()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    cin >> matrix[i];
    for (int j = 0; j < m; j++)
    {
      if (matrix[i][j] == 'A')
      {
        si = i;
        sj = j;
      }
      else if (matrix[i][j] == 'B')
      {
        ti = i;
        tj = j;
      }
    }
    par[i] = string(m, 0);
  }

  dfs(si, sj);

  if (visited[ti][tj])
  {
    cout << "YES" << endl;
    while (ti != si || tj != sj)
    {
      for (int i = 0; i < 4; i++)
      {
        int nx = ti + dx[i];
        int ny = tj + dy[i];
        if (isValid(nx, ny) && visited[ny][nx] == visited[ti][tj] - 1)
        {
          step += dc[i];
          ti = nx;
          tj = ny;
          break;
        }
      }
    }

    reverse(step.begin(), step.end());
    cout << step.size() << endl;
    cout << step;
  }
  else
  {
    cout << "NO";
  }

  return 0;
}
