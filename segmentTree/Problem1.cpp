#include <bits/stdc++.h>
using namespace std;

class SGTree
{
public:
    vector<int> seg;

    SGTree(int n)
    {
        seg.resize(4 * n + 1);
    }

    void build(int ind, int low, int high, int arr[])
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }

        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    int query(int ind, int low, int high, int l, int r)
    {
        // no overlap
        if (r < low || high < l)
            return INT_MAX;
        // complete overlap
        if (low >= l and high <= r)
        {
            return seg[ind];
        }

        int mid = (low + high) >> 1;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return min(left, right);
    }

    void update(int ind, int low, int high, int i, int val)
    {
        if (low == high)
        {
            seg[ind] = val;
            return;
        }

        int mid = (low + high) >> 1;
        if (i <= mid)
            update(2 * ind + 1, low, mid, i, val);
        else
            update(2 * ind + 2, mid + 1, high, i, val);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    SGTree sg1(n);
    sg1.build(0,0,n-1,arr);
    int n2;
    cin >> n2;
    int arr2[n2];
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }
    SGTree sg2(n);
    sg2.build(0, 0, n2 - 1, arr2);
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l1, r1,l2,r2;
            cin >> l1 >> r1>>l2>>r2;
            int min1=sg1.query(0, 0, n - 1, l1, r1) ;
            int min2=sg2.query(0,0,n2-1,l2,r2);
            cout<<min(min1,min2)<<endl;
        }
        else
        {
            int arrNo,i, val;
            cin >>arrNo>> i >> val;
            if (arrNo==1)
            {
            sg1.update(0, 0, n - 1, i, val);
            arr[i] = val;
            }
            else{
            sg2.update(0, 0, n - 1, i, val);
            arr2[i]=val;
            }
            
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    solve();
    return 0;
}
