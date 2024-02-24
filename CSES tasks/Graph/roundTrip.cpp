#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define maxi 100005

vector<vector<int>> adj(maxi);
vector<bool> vis(maxi, false);
vector<ll> parent(maxi, false);
ll n, m;
ll sv, ev;
bool pos = false;

bool dfs(ll v, ll p)
{
  vis[v] = true;
  parent[v] = p;
  for (auto x : adj[v])
  {
    if (x == p)
      continue;

    if (vis[x])
    {
      sv = x;
      ev = v;
      return true;
    }
    if (!vis[x])
    {
      if (dfs(x, v))
        return true;
    }
  }

  return false;
}

int main()
{
  cin >> n >> m;
  for (ll i = 1; i <= m; i++)
  {
    ll a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (ll i = 1; i <= n; i++)
  {
    if (!vis[i])
    {
      if (dfs(i, -1))
      {
        pos = true;
        break;
      }
    }
  }

  if (pos)
  {
    int tv = ev;
    stack<int> st;
    st.push(ev);
    while (tv != sv)
    {
      st.push(parent[tv]);
      tv = parent[tv];
    }
    st.push(ev);
    cout << st.size() << endl;

    while (!st.empty())
    {
      cout << st.top() << " ";
      st.pop();
    }
    cout << endl;
  }
  else
  {
    cout << "IMPOSSIBLE" << endl;
  }

  return 0;
}
