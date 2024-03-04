#include <bits/stdc++.h>
using namespace std;

const long long inf = 1e18;

int main()
{
  int n, x;
  cin >> n >> x;

  vector<int> coins(n);
  for (int i = 0; i < n; i++)
  {
    cin >> coins[i];
  }

  vector<long long> dp(x + 1, inf);
  dp[0] = 0;

  for (int i = 1; i <= x; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i - coins[j] >= 0)
      {
        dp[i] = min(dp[i], dp[i - coins[j]] + 1);
      }
    }
  }

  if (dp[x] != inf)
  {
    cout << dp[x] << endl;
  }
  else
  {
    cout << -1 << endl;
  }

  return 0;
}
