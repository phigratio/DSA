#include <iostream>
#include <unordered_map>
#include <vector>
#include <set> 
using namespace std;

int main(){
    vector<int> v;
    unordered_map<int, int> mp;
    while(1){
        int x;
        cin >> x;
        if(!(x+1)) break;
        v.push_back(x);
        mp[x]++;
    }
    int target;
    cin >> target;
    bool found = false;
    for(auto x: v){
        if(mp[target - x] > 0 && mp[x] > 0){
            if(found) cout << ", ";
            found = true;
            cout << "(" << x << "," << target-x << ")";
            mp[x]--;
            mp[target-x]--;
        }
    }
    if(!found) cout << "No pairs found";
}