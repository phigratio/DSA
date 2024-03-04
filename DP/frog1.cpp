#include <bits/stdc++.h>
using namespace std;
#define N 1000000
#define ll long long
vector<ll> height(N);
vector<ll> dp(N, -1);

ll dyni(ll i)
{
  ll cost = INT_MAX;
  if (i == 0)
    return 0;
  if (dp[i] != -1)
    return dp[i];
  cost = min(cost, dyni(i - 1) + abs(height[i] - height[i - 1]));

  if (i > 1)
  {
    cost = min(cost, dyni(i - 2) + abs(height[i] - height[i - 2]));
  }

  return dp[i] = cost;
}
int main()
{
  ll n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> height[i];
  }

  cout << dyni(n - 1) << endl;
}