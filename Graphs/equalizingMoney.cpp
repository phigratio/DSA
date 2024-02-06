#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 100005
vector<vector<ll>> adj(maxi);
vector<bool> vis(maxi, false);
vector<ll> arr(maxi);
ll cas;
ll n, m;
set<ll> st;

bool bfs(ll i)
{
  ll money = 0;
  ll node = 0;
  queue<int> q;
  q.push(i);
  vis[i] = true;
  node++;
  money += arr[i];

  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    for (auto v : adj[u])
    {
      if (!vis[v])
      {
        vis[v] = true;
        money += arr[v];
        node++;
        q.push(v);
      }
    }
  }

  if (money % node == 0)
  {
    ll res = money / node;
    st.insert(res);
    return true;
  }
  else
    return false;
}

int main()
{
  ll t;
  cin >> t;
  while (t--)
  {
    for (int i = 1; i <= n; i++)
    {
      adj[i].clear();
      vis[i] = 0;
      arr[i] = 0;
    }
    st.clear();
    cas++;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
      cin >> arr[i];
    }
    for (int i = 0; i < m; i++)
    {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    int test = 1;
    cout << "Case " << cas << ": ";
    for (int i = 1; i <= n; i++)
    {
      if (vis[i] == 0)
      {
        if (!bfs(i))
        {
          cout << "No" << endl;
          test = 0;
          break;
        }
      }
    }
    if (test)
    {
      if (st.size() == 1)
        cout << "Yes" << endl;
      else
      {
        cout << "No" << endl;
      }
    }
  }
  return 0;
}
