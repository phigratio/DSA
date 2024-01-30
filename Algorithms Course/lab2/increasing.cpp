#include <bits/stdc++.h>
using namespace std;
int main()
{
  long long int t;
  cin >> t;
  while (t--)
  {
    long long int n;
    cin >> n;
    long long int a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    sort(a, a + n);
    bool flag = false;
    for (int i = 0; i < n - 1; i++)
    {
      if (a[i] == a[i + 1])
      {
        flag = true;
        break;
      }
    }
    if (!flag)
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }
  return 0;
}