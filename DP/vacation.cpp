#include <bits/stdc++.h>
using namespace std;

#define N 1000000
#define ll long long

vector<vector<ll>> happy(N, vector<ll>(3));
vector<vector<ll>> dp(N, vector<ll>(3, -1));
ll n;

void dyni(ll n)
{
  dp[0][0] = happy[0][0];
  dp[0][1] = happy[0][1];
  dp[0][2] = happy[0][2];

  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (j == 0)
      {
        dp[i][j] = happy[i][j] + max(dp[i - 1][1], dp[i - 1][2]);
      }
      else if (j == 1)
      {
        dp[i][j] = happy[i][j] + max(dp[i - 1][0], dp[i - 1][2]);
      }
      else if (j == 2)
      {
        dp[i][j] = happy[i][j] + max(dp[i - 1][1], dp[i - 1][0]);
      }
    }
  }

  cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])) << endl;
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cin >> happy[i][j];
    }
  }

  dyni(n);

  return 0;
}
