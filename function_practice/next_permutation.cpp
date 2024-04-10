#include <bits/stdc++.h>
using namespace std;

/*
    next_permutation:
    用於尋找下一個排列組合,可以自訂排列的範圍,
    此function回傳bool值,當遍歷結束時會回傳false.
*/

int main(){
    string number = "123";

    cout << "String: " << number << endl;

    next_permutation(number.begin(), number.end());
    cout << "Next permutation: " << number << endl;

    /* Instore all kind of permutations */
    vector<string> number_permute;
    number = "123";
    do{
        number_permute.push_back(number);
    }while(next_permutation(number.begin(), number.end()));

    cout << "All kind of permutation: " << endl;
    for(const auto s : number_permute){
        cout << s << endl;
    }

    return 0;
}