#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> vec1;
    vector<int> vec2;

    /* 
        Using emplace instead of push_back/insert
        �ϥ�emplace function�i�H�W�[�Ĳv,�z�L�קK�إ��{�ɪ��󪺤覡,�ӬO�����q�e�����إߪ���.
    */
    for(int i=1, j=1; i<=17; i++){
        if(i%5 == 0){
            j++;
        }
        vec1.emplace_back(j);
    }

    for(int i=97; i>=85; i--){
        vec2.emplace_back(i);
    }


    cout << "---------------------- Initial vector ----------------------" << endl;

    cout << "vec1 = ";
    for(const auto x : vec1){
        cout << x << " ";
    }
    cout << endl;

    cout << "vec2 = ";
    for(const auto x : vec2){
        cout << x << " ";
    }
    cout << endl;

    cout << "------------------------------------------------------------" << endl << endl;


    /*
        Function: unique(iter, iter)
        unique��ƥu��������۾F���ƪ���,�ϥΫe�ݭn���Ƨ�.
    */
    vector<int> unique_vec1 = vec1;
    unique_vec1.erase(unique(unique_vec1.begin(), unique_vec1.end()), unique_vec1.end());

    cout << "---- Test vector(unique function) ----" << endl; 

    cout << "unique_vec1 = ";
    for(const auto x : unique_vec1){
        cout << x << " ";
    }
    cout << endl;

    cout << "--------------------------------------" << endl << endl;


    return 0;
}