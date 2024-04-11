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
        �ϥ�emplace function�i�H�W�[�Ĳv,�z�L�קK�إ��{�ɪ��󪺤覡,�ӬO�����q�e�����إߪ���.
    */
    mp.emplace(pair<string, int>("Claire", 97));

    cout << "---------------------- Initial map ----------------------" << endl;

    for(const auto n : mp){
        cout << "Name: " << n.first << "\t, Score: " << n.second << endl;
    }

    cout << "---------------------------------------------------------" << endl << endl;


    /* 
        Function: advance(*iter, numberstep),
        ���`�N�Ө��,�Ynumber steps�W�X��ɭȮɤ��|����.
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