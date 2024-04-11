#include <bits/stdc++.h>
#include <map>
using namespace std;

int main(){
    map<string, int> mp = {
        {"Alice", 87},
        {"Bob", 58},
        {"Zack", 73},
        {"Scott", 66},
        {"Saul", 45},
        {"Jack", 20}
    };

    /* 
        Using emplace instead of push_back/insert
        使用emplace function可以增加效率,透過避免建立臨時物件的方式,而是直接從容器中建立物件.
    */
    mp.emplace(pair<string, int>("Claire", 97));

    cout << "---------------------- Initial map ----------------------" << endl;

    for(const auto n : mp){
        cout << "Name: " << n.first << "\t, Score: " << n.second << endl;
    }

    cout << "---------------------------------------------------------" << endl << endl;


    /* 
        Function: advance(*iter, numberstep),
        須注意該函數,若number steps超出邊界值時不會報錯.
    */
    auto it = mp.begin();
    advance(it, 5);
    map<string, int> test = map<string,int>(mp.begin(), it);

    cout << "---------------------- Test map(advance func.) ----------------------" << endl;
    cout << "First of five element of map: " << endl;
    for(const auto n : test){
        cout << "Name: " << n.first << "\t, Score: " << n.second << endl;
    }

    cout << "---------------------------------------------------------------------" << endl;

    return 0;
}