#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 1e6
vector<ll> arr(maxi);
void merge(ll left, ll mid, ll right)
{
  ll subArrayOne = mid - left + 1;
  ll subArrayTwo = right - mid;

  auto *leftArray = new int[subArrayOne],
       *rightArray = new int[subArrayTwo];

  for (auto i = 0; i < subArrayOne; i++)
  {
    leftArray[i] = arr[left + i];
  }

  for (auto i = 0; i < subArrayTwo; i++)
  {
    rightArray[i] = arr[mid + 1 + i];
  }

  auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
  int indexOfMergedArray = left;

  while (indexOfSubArrayOne < subArrayOne and indexOfSubArrayTwo < subArrayTwo)
  {
    if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
    {
      arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
      indexOfSubArrayOne++;
    }
    else
    {
      arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
      indexOfSubArrayTwo++;
    }
  }

  while (indexOfSubArrayOne < subArrayOne)
  {
    arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
    indexOfSubArrayOne++;
    indexOfMergedArray++;
  }
  while (indexOfSubArrayTwo < subArrayTwo)
  {
    arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
    indexOfSubArrayTwo++;
    indexOfMergedArray++;
  }
  delete[] leftArray;
  delete[] rightArray;
}

void mergeSort(ll begin, ll end)
{
  if (begin >= end)
  {
    return;
  }

  ll mid = begin + (end - begin) / 2;
  mergeSort(begin, mid);
  mergeSort(mid + 1, end);
  merge(begin, mid, end);
}
int main()
{
  ll n, w;
  cin >> n >> w;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.begin() + n);
  ll start = 0, end = n - 1;
  ll count = 0;
  while (start <= end)
  {
    if (arr[start] + arr[end] > w)
    {
      count++;
      end--;
    }
    else
    {
      start++;
      end--;
      count++;
    }
  }

  cout << count << endl;
}