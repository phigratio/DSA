#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    ll ans = 0;
    ll a, b;
    cin >> a >> b;
    ll diff = b - a;
    while (diff >= 4)
    {
      ll min = sqrt(diff);
      diff = diff - (min * min);
      ans += (2 * min) - 1;
    }

    cout << diff + ans << endl;
  }
  return 0;
}