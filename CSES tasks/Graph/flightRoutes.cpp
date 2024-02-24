#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 1e5
ll n, m, k;
priority_queue<pair<ll, ll>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
vector<priority_queue<ll>> shera(maxi);
vector<vector<pair<ll, ll>>> adj(maxi);
void dijakstra()
{
  shera[1].push(0);
  pq.push({0, 1});

  while (!pq.empty())
  {
    auto temp = pq.top();
    pq.pop();

    if (temp.first > shera[temp.second].top())
    {
      continue;
    }

    for (auto &child : adj[temp.second])
    {
      ll val = temp.first + child.second;
      if (shera[child.first].size() < k)
      {
        shera[child.first].push(val);
        pq.push({val, child.first});
      }
      else if (val < shera[child.first].top())
      {
        shera[child.first].pop();
        shera[child.first].push(val);
        pq.push({val, child.first});
      }
    }
  }
  vector<ll> ans;
  while (!shera[n].empty())
  {
    ans.push_back(shera[n].top());
    shera[n].pop();
  }
  reverse(ans.begin(), ans.end());

  for (auto i : ans)
  {
    cout << i << " ";
  }
}

int main()
{

  cin >> n >> m >> k;
  for (int i = 0; i < m; i++)
  {
    ll src, dest, weight;
    cin >> src >> dest >> weight;
    adj[src].push_back({dest, weight});
  }

  dijakstra();
}