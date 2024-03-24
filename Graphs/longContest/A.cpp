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

char matrix[1002][1002];
bool vis[1002][1002];
ll dx[4] = {-1, 1, 0, 0};
ll dy[4] = {0, 0, -1, 1};
ll ans = 0;
ll n, m;

bool isValid(ll x, ll y)
{
  if (x < 0 || y < 0 || x >= n || y >= m || vis[x][y] || matrix[x][y] == '#')
    return false;
  return true;
}

void bfs(ll i, ll j)
{
  queue<pair<ll, ll>> q;
  q.push({i, j});
  vis[i][j] = true;

  while (!q.empty())
  {
    ll x = q.front().f;
    ll y = q.front().s;
    q.pop();

    for (int k = 0; k < 4; k++)
    {
      ll dxx = x + dx[k];
      ll dyy = y + dy[k];
      if (isValid(dxx, dyy))
      {
        vis[dxx][dyy] = true;
        q.push({dxx, dyy});
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
      vis[i][j] = false; // Initialize vis array properly
    }
  }

  ans = 0; // Reset ans for each test case
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (matrix[i][j] == '.' && !vis[i][j])
      {
        bfs(i, j);
        ans++;
      }
    }
  }
  cout << ans << endl;
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
