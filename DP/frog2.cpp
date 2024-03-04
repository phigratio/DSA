#include <bits/stdc++.h>
using namespace std;
#define N 1000000
#define ll long long
vector<ll> height(N);
vector<ll> dp(N, -1);
ll k;
ll dyni(ll i)
{
  ll cost = INT_MAX;
  if (i == 0)
    return 0;
  if (dp[i] != -1)
    return dp[i];

  for (int j = 1; j <= k; j++)
  {
    if (i - j >= 0)
    {
      cost = min(cost, dyni(i - j) + abs(height[i] - height[i - j]));
    }
  }

  return dp[i] = cost;
}
int main()
{
  ll n;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    cin >> height[i];
  }

  cout << dyni(n - 1) << endl;
}