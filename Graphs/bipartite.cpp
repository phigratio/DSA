#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 200
vector<int> hello;
vector<vector<int>> adj(maxi);
vector<bool> vis(maxi);
vector<bool> color(maxi);
bool pos = true;
vector<ll> ans[2];

void dfs(ll start, ll col)
{
  if (vis[start])
  {
    if (color[start] != col)
    {
      pos = false;
    }
    return;
  }

  vis[start] = true;
  color[start] = col;

  for (auto child : adj[start])
  {
    dfs(child, 1 - col);
  }
}

int main()
{
  ll n, m;
  cin >> n >> m;

  while (n > 0)
  {
    adj.assign(maxi, vector<int>());
    vis.assign(maxi, false);
    color.assign(maxi, false);
    pos = true;

    for (int i = 0; i < m; i++)
    {
      ll a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
      if (!vis[i])
      {
        dfs(i, 0);
      }
    }

    if (pos)
    {
      cout << "BICOLORABLE." << endl;
    }
    else
    {
      cout << "NOT BICOLORABLE." << endl;
    }

    cin >> n >> m;

    if (n == 0)
    {
      break;
    }
  }

  return 0;
}
