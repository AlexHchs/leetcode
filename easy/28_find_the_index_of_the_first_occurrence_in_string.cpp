#include <bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle){
    if(haystack == needle){
        return 0;
    }
    
    if(haystack.size() < needle.size()){
        return -1;
    }

    for(int i=0; i<=haystack.size()-needle.size(); i++){
        string judge = haystack.substr(i, needle.size());
        if(judge == needle){
            return i;
        }
    }

    return -1;
}


int main(){
    string haystack = "sadbustsad";
    string needle = "bust";
    int result;

    cout << "Input: haystack = " << haystack << ", needle = " << needle << endl;

    result = strStr(haystack, needle);

    cout << "Output: " << result << endl;

    return 0;
}