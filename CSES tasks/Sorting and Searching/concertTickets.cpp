#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  ll n, m;
  cin >> n >> m;
  multiset<int> tickets;
  ll x, y;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    tickets.insert(x);
  }

  for (int i = 0; i < m; i++)
  {
    cin >> y;

    auto it = tickets.upper_bound(y);

    if (it == tickets.begin())
    {
      cout << -1 << endl;
    }
    else
    {
      cout << *(--it) << endl;
      tickets.erase(it);
    }
  }
}
