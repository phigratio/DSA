#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define maxi 500005
vector<vector<int>> edges(maxi);
vector<bool> vis(maxi, false);

int main()
{
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int k;
    cin >> k;
    vector<int> v(k);
    for (int j = 0; j < k; j++)
    {
      cin >> v[j];
      --v[j];
    }
    for (int j = 0; j + 1 < k; j++)
    {
      edges[v[j]].push_back(v[j + 1]);
      edges[v[j + 1]].push_back(v[j]);
    }
  }

  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    if (!vis[i])
    {
      vector<int> component;

      queue<int> q;
      q.push(i);

      while (!q.empty())
      {
        int x = q.front();
        q.pop();

        if (vis[x])
          continue;
        vis[x] = true;
        component.push_back(x);

        for (int y : edges[x])
        {
          if (!vis[y])
          {
            q.push(y);
          }
        }
      }

      for (int x : component)
      {
        a[x] = component.size();
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
}
