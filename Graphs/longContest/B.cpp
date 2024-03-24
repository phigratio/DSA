#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
#define pb push_back
#define f first
#define s second
ll dx[4] = {-1, 1, 0, 0};
ll dy[4] = {0, 0, -1, 1};
char d[4] = {'U', 'D', 'L', 'R'};
ll n, m;
char matrix[1002][1002];
bool vis[1002][1002];
ll parent[1002][1002];
ll si, sj, ei, ej;
string ans = "";
bool isValid(ll x, ll y)
{
  if (x < 0)
    return false;
  else if (y < 0)
    return false;
  else if (x >= n)
    return false;
  else if (y >= m)
    return false;
  else if (matrix[x][y] == '#')
    return false;

  return true;
}
void bfs(ll x, ll y)
{
  queue<pair<ll, ll>> q;
  q.push({x, y});
  vis[x][y] = true;
  while (!q.empty())
  {
    ll fx = q.front().f;
    ll fy = q.front().s;
    q.pop();
    for (int i = 0; i < 4; i++)
    {
      ll newX = fx + dx[i];
      ll newY = fy + dy[i];
      if (isValid(newX, newY) and !vis[newX][newY])
      {
        q.push({newX, newY});
        vis[newX][newY] = true;
        parent[newX][newY] = i;
        if (matrix[newX][newY] == 'B')
        {
          string path = "";
          ll bx = newX, by = newY;
          while (bx != si || by != sj)
          {
            ll dir = parent[bx][by];
            path += d[dir];
            bx = bx - dx[dir], by = by - dy[dir];
          }
          reverse(path.begin(), path.end());
          ans = path;
          return;
        }
      }
    }
  }
}
void muqtu()
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

  bfs(si, sj);
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
  return;
}
int main()
{
  faster;
  ll t;
  t = 1;
  while (t--)
  {
    muqtu();
  }
  return 0;
}