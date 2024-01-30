#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int x;
  cin >> x;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  int count = 0;
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    if (sum < x)
    {
      sum += arr[i];
      count++;
      if (sum + arr[i + 1] > x)
      {
        break;
      }
    }
    else if (sum == x)
    {
      count += 1;
      break;
    }
    else
    {
      break;
    }
  }

  cout << count << endl;

  return 0;
}