#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

int main(){
    unordered_map<string, int> mp;
    set<string> s;
    string str;
    while(cin >> str){
        if(str[str.length()-1] == ','){
            str[str.length()-1] = '\0';
        }
        s.insert(str);
        mp[str]++;
    }
    for(auto x: s){
        if(mp[x]-1){
            cout << x << " " << mp[x] << endl;
        }
    }
}