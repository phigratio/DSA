#include <bits/stdc++.h>
using namespace std; 
void heapifyMin(vector<int> &arr,int n,int i)
{
    int smallestElement=i;
    int leftChild=2*i+1;
    int rightChild=2*i+2;

    if (leftChild < n and arr[smallestElement] > arr[leftChild]) {
      smallestElement = leftChild;
    }
    if (rightChild < n and arr[smallestElement] > arr[rightChild])
    {
        smallestElement=rightChild;
    }
    if(smallestElement!=i)
    {
        swap(arr[smallestElement],arr[i]);
        heapifyMin(arr,n,smallestElement);
    }
}
vector<int> buildMinHeap(vector<int> &arr)
{
    int n=arr.size();
    for(int i=n/2-1;i>=0;i--)
    {
        heapifyMin(arr,n,i);
    }

    return(arr);
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
           cin>>arr[i];
        }
        buildMinHeap(arr);
        
    }
    
}