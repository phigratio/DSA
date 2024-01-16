// Implement Bubble Sort, Selection Sort and Merge Sort. A power point file is provided containing
// the algorithm/code for those sorting.

#include <bits/stdc++.h>
using namespace std;
void bubbleSort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

void insertionSort(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 and arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

void selectionSort(int arr[], int n)
{
  int mini;
  for (int i = 0; i < n - 1; i++)
  {
    mini = i;
    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[mini])
      {
        mini = j;
      }
    }
    if (mini != i)
    {
      swap(arr[mini], arr[i]);
    }
  }
}

void merge(int arr[], int left, int mid, int right)
{
  int subArrayone = mid - left + 1;
  int subArrayTwo = right - mid;

  int leftSubArray[subArrayone];
  int rightSubArray[subArrayTwo];

  for (int i = 0; i < subArrayone; i++)
  {
    leftSubArray[i] = arr[left + i];
  }
  for (int j = 0; j < subArrayTwo; j++)
  {
    rightSubArray[j] = arr[j + mid + 1];
  }

  int i = 0;
  int j = 0;
  int k = left;

  while (i < subArrayone and j < subArrayTwo)
  {
    if (leftSubArray[i] <= rightSubArray[j])
    {
      arr[k] = leftSubArray[i];
      i++;
    }
    else
    {
      arr[k] = rightSubArray[j];
      j++;
    }
    k++;
  }

  while (i < subArrayone)
  {
    arr[k] = leftSubArray[i];
    i++;
    k++;
  }
  while (j < subArrayTwo)
  {
    arr[k] = rightSubArray[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int begin, int end)
{
  if (begin >= end)
  {
    return;
  }
  int mid = begin + (end - begin) / 2;
  mergeSort(arr, begin, mid);
  mergeSort(arr, mid + 1, end);
  merge(arr, begin, mid, end);
}

int main()
{
}