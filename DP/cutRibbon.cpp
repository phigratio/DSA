#include <bits/stdc++.h>
using namespace std;
#define N 4005
#define ll long long
vector<ll> dp(N, -1);
ll a, b, c;

ll dyni(ll i)
{
  if (i == 0)
    return 0;
  if (dp[i] != -1)
    return dp[i];

  ll cost = INT_MIN;

  if (i - a >= 0)
    cost = max(cost, 1 + dyni(i - a));
  if (i - b >= 0)
    cost = max(cost, 1 + dyni(i - b));
  if (i - c >= 0)
    cost = max(cost, 1 + dyni(i - c));

  return dp[i] = cost;
}

int main()
{
  ll n;
  cin >> n >> a >> b >> c;

  cout << dyni(n) << endl;

  return 0;
}
