#include <bits/stdc++.h>
using namespace std;
const unsigned int MOD = 1e9 + 7;
const int INF = 1e9;
const int maxi = 1e6 + 1;
#define ll long long
#define pb push_back
#define f first
#define s second
ll n, x;
vector<ll> coins(101, -1);

void muqtu()
{

  cin >> n >> x;

  for (int i = 0; i < n; i++)
  {
    cin >> coins[i];
  }

  vector<vector<unsigned int>> dp(n + 1, vector<unsigned int>(x + 1, 0));

  for (int i = 0; i <= n; i++)
  {
    dp[i][0] = 1;
  }
  for (int i = n - 1; i >= 0; i--)
  {
    for (int sum = 1; sum <= x; sum++)
    {
      unsigned int skip = dp[i + 1][sum];
      unsigned int pick = 0;
      if (coins[i] <= sum)
      {
        pick = dp[i][sum - coins[i]];
      }

      dp[i][sum] = (pick + skip) % MOD;
    }
  }
  cout << dp[0][x] << endl;
}

int main()
{

  ll t;
  t = 1;
  while (t--)
  {
    muqtu();
  }
  return 0;
}
