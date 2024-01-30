#include <bits/stdc++.h>
using namespace std;
#define maxi 100000
int n, m;
vector<vector<int>> adj(maxi);
vector<bool> visited(maxi, false);
vector<int> bridges;

void dfs(int u)
{
  visited[u] = true;
  for (auto v : adj[u])
  {
    if (!visited[v])
    {
      dfs(v);
    }
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 1; i <= n; i++)
  {
    if (!visited[i])
    {
      bridges.push_back(i);
      dfs(i);
    }
  }
  cout << bridges.size() - 1 << endl;
  for (int i = 0; i < bridges.size() - 1; i++)
  {
    cout << bridges[i] << " " << bridges[i + 1] << endl;
  }
  return 0;
}