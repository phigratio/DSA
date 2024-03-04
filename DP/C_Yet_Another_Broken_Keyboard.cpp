#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, k;
string s;
vector<ll> dpMain(1e6 + 1, 0);
vector<ll> dp(1e6 + 1, 0);
vector<bool> typeable(26, false);

void dyni()
{
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (dp[i] == 0)
    {
      dpMain[i + 1] = 0;
    }
    else
    {
      dpMain[i + 1] = dpMain[i] + 1;
    }

    ans += dpMain[i + 1];
  }

  cout << ans << endl;
  return;
}
int main()
{
  cin >> n >> k;
  cin >> s;
  for (int i = 0; i < k; i++)
  {
    char c;
    cin >> c;
    typeable[c - 'a'] = true;
  }

  for (int i = 0; i < n; i++)
  {
    if (typeable[s[i] - 'a'])
    {
      dp[i] = 1;
    }
  }

  dyni();
}