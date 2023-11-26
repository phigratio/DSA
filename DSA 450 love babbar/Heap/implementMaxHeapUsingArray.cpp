#include <bits/stdc++.h> 
using namespace std;
void maxHeap(vector<int> &arr,int n,int i)
{
	int largestElement=i;
	int leftChild=2*i+1;
	int rightChild=2*i+2;

	if(rightChild<n and arr[largestElement]<arr[rightChild])
	{
		largestElement=rightChild;
	}
	
	if(leftChild<n and arr[largestElement]<arr[leftChild])
	{
		largestElement=leftChild;
	}
	if(largestElement!=i)
	{
		swap(arr[largestElement],arr[i]);
		maxHeap(arr,n,largestElement);
	}
}
vector<int> buildMaxHeap(vector<int> arr, int n)
{	
	
	for(int i=n/2-1;i>=0;i--)
	{
		maxHeap(arr, n, i);
	}
	return arr;
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
        buildMaxHeap(arr,n);
        
    }
    
}