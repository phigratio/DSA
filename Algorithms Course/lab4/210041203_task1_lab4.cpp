#include <bits/stdc++.h>
#define SIZE 5005
#define ll_MAX 2000000000
#define MOD 20071027
#define clr(a) memset(a, 0, sizeof a)
#define reset(a) memset(a, -1, sizeof a)
#define ll long long
using namespace std;
ll n, m, row, column;

ll nthg;

vector<pair<ll, ll>> adj[SIZE];
bool visited[SIZE];
ll weight[SIZE];
ll weight2[SIZE];
ll minWeight[SIZE];
bool back[SIZE];

ll dijkstra(ll start, ll end)
{
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
  q.push({0, start});
  clr(visited);
  reset(weight);
  reset(weight2);
  clr(back);
  weight[start] = 0;
  pair<ll, ll> node, temp;
  for (ll i = 1; i <= n; i++)
  {
    minWeight[i] = ll_MAX;
    for (ll j = 0; j < adj[i].size(); j++)
      minWeight[i] = min(minWeight[i], 2 * adj[i][j].second);
  }

  while (!q.empty())
  {
    node = q.top();
    q.pop();

    if (visited[node.second])
    {
      if (weight[node.second] < node.first && (weight2[node.second] == -1 || weight2[node.second] >= node.first))
        weight2[node.second] = node.first;
      else
        continue;
    }
    else
      visited[node.second] = true;

    for (ll i = 0; i < adj[node.second].size(); i++)
    {
      temp = adj[node.second][i];
      if (weight[temp.first] == -1 || weight[temp.first] > node.first + temp.second)
      {
        q.push({node.first + temp.second, temp.first});
        weight2[temp.first] = weight[temp.first];
        weight[temp.first] = node.first + temp.second;
      }
      else if (weight2[temp.first] == -1 || weight2[temp.first] > node.first + temp.second)
      {
        if (weight[temp.first] != node.first + temp.second)
          q.push({node.first + temp.second, temp.first});
      }
    }

    if (!back[node.second])
    {
      q.push({weight[node.second] + minWeight[node.second], node.second});
      back[node.second] = true;
    }
  }

  return weight2[end];
}

int main()
{

  ll i, j, k, l;
  ll x, y;
  ll tc, t;

  cin >> tc;

  for (t = 1; t <= tc; t++)
  {
    cin >> n >> m;
    for (i = 1; i <= n; i++)
      adj[i].clear();

    for (i = 0; i < m; i++)
    {
      cin >> x >> y >> l;
      adj[x].push_back({y, l});
      adj[y].push_back({x, l});
    }

    ll result = dijkstra(1, n);

    cout << "Case " << t << ": " << result << endl;
  }

  return 0;
}
