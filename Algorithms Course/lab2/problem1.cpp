#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int x;
  cin >> x;
  int num = 2 * n;
  int arr[num];
  for (int i = 0; i < num; i++)
  {
    cin >> arr[i];
  }
  sort(arr, arr + num);
  int mid = (num / 2);
  for (int i = 0; i < n; i++)
  {

    if (arr[mid] - arr[i] >= x)
    {
      mid++;
      continue;
    }
    else
    {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
  return 0;
}