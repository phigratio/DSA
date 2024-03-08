#include <bits/stdc++.h>
using namespace std;

char matrix[1010][1010];
bool visited[1010][1010];
queue<pair<int, int>> q;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int dis[1010][1010];

int main()
{
  int r, c, ans = 0;
  int len = INT_MAX;
  cin >> r >> c;

  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cin >> matrix[i][j];

      if (matrix[i][j] == 'E')
      {
        q.push({i, j});
        visited[i][j] = true;
        dis[i][j] = 0;
      }
    }
  }

  while (!q.empty())
  {
    pair<int, int> temp = q.front();
    q.pop();

    for (int ways = 0; ways < 4; ways++)
    {
      int way1 = temp.first + dx[ways];
      int way2 = temp.second + dy[ways];

      if (way1 >= 0 and way2 >= 0 and way1 < r and way2 < c and !visited[way1][way2] and matrix[way1][way2] != 'T')
      {
        visited[way1][way2] = true;
        q.push({way1, way2});
        dis[way1][way2] = dis[temp.first][temp.second] + 1;

        if (matrix[way1][way2] == 'S')
        {
          len = min(len, dis[way1][way2]);
        }
        else if (dis[way1][way2] <= len && isdigit(matrix[way1][way2]))
        {
          ans += matrix[way1][way2] - '0';
        }
      }
    }
  }

  cout << ans << endl;
  return 0;
}
