#include <bits/stdc++.h>
using namespace std;

string simplifyPath(string path){
    string token = "";
    string result;
    stringstream ss(path);
    stack<string> store;

    while(getline(ss, token, '/')){
        if(token == "" || token == "."){
            continue;
        }
        else if(token != ".."){
            store.push(token);
        }
        else if(!store.empty()){
            store.pop();
        }
    }

    while(!store.empty()){
        result = "/" + store.top() + result;
        store.pop();
    }

    if(result.size() == 0){
        return "/";
    }

    return result;
}

int main(){
    string input = "/home//foo/../a/./b/../../c/";
    string result;

    cout << "Input: path = " << input << endl;

    result = simplifyPath(input);

    cout << "Output: " << result << endl; 

    return 0;
}