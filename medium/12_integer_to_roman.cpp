#include <bits/stdc++.h>
#include <map>
using namespace std;

string intToRoman(int num) {
    int times = 1;
    string result = "";
    map<int, string> mp{
        {1, "I"},
        {4, "IV"},
        {5, "V"},
        {9, "IX"},
        {10, "X"},
        {40, "XL"},
        {50, "L"},
        {90, "XC"},
        {100, "C"},
        {400, "CD"},
        {500, "D"},
        {900, "CM"},
        {1000, "M"}
    };

    while(num > 0){
        int temp = num % 10;
        if(mp.find(temp*times) != mp.end()){
            result = mp[temp*times] + result;
        } 
        else{
            for(int i=0; i<temp%5; i++){
                result = mp[times] + result;
            }
            if(temp/5 > 0){
                result = mp[5*times] + result;
            }
        }
        num /= 10;
        times *= 10;                                            // This place do not use pow() function because pow(10, 2) will cause 99 result
    }

    return result;
}

string intToRoman2(int num){
    string result;
    int number[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string roman[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

    for(int i=0; i<13; i++){
        while(num >= number[i]){
            result.append(roman[i]);
            num -= number[i];
        }
    }

    return result;
}

int main(){
    int input = 1994;

    cout << "Input: " << input << endl;
    cout << "Output (Solution 1): " << intToRoman(input) << endl;
    cout << "Output (Solution 2): " << intToRoman2(input) << endl;
}