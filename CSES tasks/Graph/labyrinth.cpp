#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m;
ll si, sj;
ll ei, ej;
char matrix[1001][1001];
bool vis[1001][1001];
int parent[1001][1001];
queue<pair<int, int>> q;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
char d[4] = {'R', 'L', 'D', 'U'};
string ans = "";

void bfs()
{
  q.push({si, sj});
  vis[si][sj] = true;

  while (!q.empty())
  {
    pair<int, int> u = q.front();
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      pair<int, int> temp = {u.first + dx[i], u.second + dy[i]};

      if (temp.first < 0 or temp.second < 0 or temp.first >= n or temp.second >= m)
      {
        continue;
      }
      if (matrix[temp.first][temp.second] == '#')
      {
        continue;
      }
      if (vis[temp.first][temp.second])
      {
        continue;
      }

      vis[temp.first][temp.second] = true;
      parent[temp.first][temp.second] = i; // Update the parent array

      q.push(temp);
      if (matrix[temp.first][temp.second] == 'B')
      {
        // Reconstruct the path
        pair<int, int> current = temp;
        while (current != make_pair(static_cast<int>(si), static_cast<int>(sj)))
        {
          int direction = parent[current.first][current.second];
          ans += d[direction];
          current = {current.first - dx[direction], current.second - dy[direction]};
        }

        reverse(ans.begin(), ans.end()); // Reverse the path string
        return;
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

      if (matrix[i][j] == 'A')
      {
        si = i, sj = j;
      }
      else if (matrix[i][j] == 'B')
      {
        ei = i, ej = j;
      }
    }
  }

  bfs();

  if (vis[ei][ej])
  {
    cout << "YES" << endl;
    cout << ans.size() << endl;
    cout << ans << endl;
  }
  else
  {
    cout << "NO" << endl;
  }

  return 0;
}
