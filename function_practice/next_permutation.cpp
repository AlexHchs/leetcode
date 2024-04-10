#include <bits/stdc++.h>
using namespace std;

/*
    next_permutation:
    �Ω�M��U�@�ӱƦC�զX,�i�H�ۭq�ƦC���d��,
    ��function�^��bool��,��M�������ɷ|�^��false.
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