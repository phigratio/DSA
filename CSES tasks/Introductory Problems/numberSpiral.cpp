#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    ll a, b;
    cin >> a >> b;

    if (a < b)
    {
      if (b % 2 == 1)
      {
        cout << b * b - a + 1 << endl;
      }
      else
      {
        cout << (b - 1) * (b - 1) + a << endl;
      }
    }
    else
    {
      if (a % 2 == 0)
      {
        cout << a * a - b + 1 << endl;
      }
      else
      {
        cout << (a - 1) * (a - 1) + b << endl;
      }
    }
  }

  return 0;
}
