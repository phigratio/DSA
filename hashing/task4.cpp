// Task 4 — Babelfish

// Problem Statement
// You have just moved from Waterloo to a big city. The people here speak an incomprehensible dialect of a foreign language. Fortunately, you have a dictionary to help you understand them.

// Input
// Input consists of several dictionary entries, followed by a blank line, followed by a message consisting of many words. Each dictionary entry is a line containing an English word, followed by a space and a foreign language word. No foreign word appears more than once in the dictionary. The message is a sequence of words in the foreign language, one word on each line.

// Output
// Output is the message translated to English, one word per line. Foreign words not in the dictionary should be translated as ‘eh’.

// Sample Test Case(s)

// Input

// dog ogday
// cat atcay
// pig igpay
// froot ootfray
// loops oopslay

// atcay
// ittenkay
// oopslay

// Output

// cat
// eh
// loops


#include <iostream>
#include <unordered_map>

using namespace std;

void dictionary(unordered_map<string, string> &mp, string s){
    string sx[2];
    int i=0;
    for(auto x: s){
        if(x == ' '){
            i++;
            continue;
        }
        sx[i] += x;
    }
    mp[sx[1]] = sx[0];
}

int main(){
    string s;
    unordered_map<string, string> mp;
    while(getline(cin, s)){
        if(s=="") continue;
        bool flag = false;
        for(auto x: s){
            if(x == ' '){
                dictionary(mp, s);
                flag = true;
            }
        }
        if(flag) continue;
        cout << (mp[s]==""?"eh":mp[s]) << endl; 
    }
}