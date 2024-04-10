#include <bits/stdc++.h>
#include <map>
using namespace std;

int romanToInt(string s) {
    int ptr = s.size() - 1;
    int result = 0;
    map<char, int> mp = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    /* ------------------------------------------
        Method: Judge before and after of the ptr
    ------------------------------------------- */ 

    // while(ptr >= 0){
    //     if(ptr == 0){
    //         result = result + mp[s[ptr]];
    //         break;
    //     }
    //     if((s[ptr] == 'X' || s[ptr] == 'V') && s[ptr-1] == 'I'){
    //         result = result + (mp[s[ptr]] - 1);
    //         ptr -= 2;
    //     }
    //     else if((s[ptr] == 'L' || s[ptr] == 'C') && s[ptr-1] == 'X'){
    //         result = result + (mp[s[ptr]] - 10);
    //         ptr -= 2;
    //     }
    //     else if((s[ptr] == 'D' || s[ptr] == 'M') && s[ptr-1] == 'C'){
    //         result = result + (mp[s[ptr]] - 100);
    //         ptr -= 2;
    //     }
    //     else{
    //         result = result + mp[s[ptr]];
    //         ptr--; 
    //     } 
    // }

    /* ---------------------
        Method: Simple code
    ---------------------- */

    while(ptr > 0){
        if(mp[s[ptr]] <= mp[s[ptr-1]]){
            result += mp[s[ptr]];
            ptr--;
        }
        else{
            result += mp[s[ptr]];
            ptr--;
            result -= mp[s[ptr]];
            ptr--;
        }
    }
    if(ptr == 0)
        result += mp[s[ptr]];

    return result;
}

int main(){
    string input = "MCMXCIV";

    cout << "Input: " << input << endl;
    cout << "Output: " << romanToInt(input) << endl;
}