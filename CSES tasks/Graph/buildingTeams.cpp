#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 100005
vector<vector<int>> adj(maxi);
vector<bool> vis(maxi, false);
vector<bool> team(maxi);
vector<ll> dist(maxi);
queue<int> q;
bool pos;
void dfs(int u)
{
  for (int v : adj[u])
  {
    if (!vis[v])
    {
      team[v] = !team[u];
      vis[v] = true;
      dfs(v);
    }
    else
    {
      if (team[v] == team[u])
      {
        pos = false;
      }
    }
  }
}
int main()
{
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++)
  {
    ll a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  pos = true;
  for (int i = 0; i <= n; i++)
  {
    if (!vis[i])
    {
      vis[i] = true;
      dfs(i);
    }
  }
  if (!pos)
  {
    cout << "IMPOSSIBLE" << endl;
  }
  else
  {
    for (int i = 1; i <= n; i++)
    {
      if (team[i])
        cout << 1 << " ";
      else
      {
        cout << 2 << " ";
      }
    }
    cout << endl;
  }
}